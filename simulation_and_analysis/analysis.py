"""Analysis class"""
import sys
import math
from time import sleep
from node import Node
from executor import Executor
from timer import Timer
from subscription import Subscription
from message import Message
from entry import Entry


class Analysis:
    """Global analysis object"""
    now = 0
    past_polling_points = 0
    nodes = 0
    executor = 0

    sim_time = False

    def __init__(self):
        self.now = 0
        self.past_polling_points = []
        self.nodes = []
        self.executor = Executor()

    def add_node_to_executor(self, node):
        """Adds node to executor in the analysis"""
        self.executor.add_node(node)

    # Time and Timer Functions

    def update_timer_buffers(self):
        """Updates the timer buffers using the current time and last polling point"""
        timers = self.executor.get_timers()
        # If there was no past polling point, find the timers with the lowest phase
        # and set their activation_buffer
        if len(self.past_polling_points) == 0:
            min_phase = float("inf")
            min_set = []
            for elem in timers:
                if elem.phase < min_phase:
                    min_set.clear()
                    min_phase = elem.phase
                    min_set.append(elem)
                elif elem.phase == min_phase:
                    min_set.append(elem)
            elem: Timer
            for elem in min_set:
                elem.modify_activation_buffer(1)
            self.now = min_phase
        # Else, update the number of activations by using the difference between
        # the number of activations since the last polling point
        else:
            last_time = self.past_polling_points[-1]
            for elem in timers:
                # Determine the next time a timer (or more) are activated.
                # Inclusive t with ceil, exclusive with floor+1
                activations_past = math.floor(
                    round((last_time-elem.phase)/elem.period, 10))+1
                activations_now = math.floor(
                    round((self.now-elem.phase)/elem.period, 10))+1
                elem.modify_activation_buffer(activations_now-activations_past)

    def determine_next_polling_point(self):
        """Sets the current time to the next time at which a timer will be activated"""
        timers = self.executor.get_timers()
        next_activation = float("inf")
        for elem in timers:
            next_activation = min(next_activation, (math.ceil(
                (self.now-elem.phase)/elem.period))*elem.period+elem.phase)
        self.now = next_activation

    # Ready Collection Functions

    def get_ready_subscriptions(self):
        """Collects all subscriptions with a non-empty buffer"""
        # Collect ready subscriptions with elements in their dds_buffer
        ready_subscriptions = []
        elem: Subscription
        for elem in self.executor.get_subscriptions():
            if elem.has_dds_messages():
                ready_subscriptions.append(elem)
        return ready_subscriptions

    def get_ready_timers(self):
        """Collects all timers with a non-empty buffer"""
        # Collect ready timers with activation_buffer > 0
        ready_timers = []
        elem: Timer
        for elem in self.executor.get_timers():
            if elem.get_activation_buffer() > 0:
                ready_timers.append(elem)
        return ready_timers

    # Simulation

    def simulate_next_processing_window(self):
        """Simulate executor cycle for one processing window"""
        self.update_timer_buffers()

        ready_subscriptions = self.get_ready_subscriptions()
        ready_timers = self.get_ready_timers()

        self.past_polling_points.append(self.now)

        self.execute_timers(ready_timers)
        self.execute_subscriptions(ready_subscriptions)

        if (len(self.get_ready_subscriptions())+len(self.get_ready_timers())) == 0:
            self.determine_next_polling_point()

    # Subscription and Timer Execution Functions

    def execute_subscriptions(self, ready_subscriptions):
        """Execute subscriptions and manage messages and registers"""
        elem: Subscription
        for elem in ready_subscriptions:
            # A subscription never starts a chain, so we can start the analysis after the wcet
            self.now += elem.get_wcet()
            # We start the analysis after the WCET
            fusion_message = Message()
            # Collect and add the entries from the current subscription
            newest_message: Message
            newest_message = elem.get_newest_buffer()
            entry: Entry
            for entry in newest_message.get_entries():
                fusion_message.add_entry(
                    Entry(entry.data_age, entry.reaction_time, entry.history))
            # Collect entries from register
            if elem.has_subscription_dependencies():
                for forward_message in elem.forward_messages:
                    for entry in forward_message.entries:
                        fusion_message.add_entry(
                            Entry(entry.data_age, entry.reaction_time, entry.history))
                elem.forward_messages.clear()
            # Extend history
            fusion_message.extend_history(
                self.executor.get_subscription_priority(elem))
            # We first update the data age given the previous message
            elem.update_analysis_data_age(self.now)
            # We update the latest message
            elem.set_latest_message(fusion_message)
            # We remove the first element of the buffer that we just used
            elem.advance_buffer()
            # We add new register entries and update the data age of existing ones
            elem.update_register_entries()
            elem.update_register_data_age()
            elem.update_register_reaction_time()
            # Update the analysis registers
            elem.update_analysis_reaction_time(self.now)
            elem.update_analysis_data_age(self.now)

            for forward in elem.get_subscription_forwards():
                append = True
                forward_message = Message()
                for entry in elem.register:
                    forward_message.add_entry(
                        Entry(entry.data_age, entry.reaction_time, entry.history))
                # forward_message.extend_history(self.executor.get_priority(forward))
                for entry in forward_message.entries:
                    for fw_message in forward.forward_messages:
                        for fw_entry in fw_message.entries:
                            if fw_entry.history == entry.history:
                                append = False
                                fw_entry.data_age = entry.data_age
                if append:
                    forward.forward_messages.append(forward_message)

            if self.sim_time:
                sleep(elem.get_wcet())

            # Publish the message to the topic
            if elem.get_pub_topic() != "":
                topic = elem.get_pub_topic()
                publish_message = Message()
                for entry in elem.register:
                    publish_message.add_entry(Entry(entry.data_age,entry.reaction_time,entry.history))
                subscription: Subscription
                for subscription in self.executor.get_subscriptions():
                    if subscription.sub_topic == topic:
                        subscription.receive_dds_message(publish_message)

    def execute_timers(self, ready_timers):
        """Execute timers and manage messages and registers"""
        # Execute timers
        elem: Timer
        for elem in ready_timers:
            elem.modify_activation_buffer(-1)
            # Create message
            message = Message()
            # If the timer creates the message, it determines the reaction time and data age values
            if not elem.has_subscription_dependencies():
                history = [self.executor.get_timer_priority(elem)]
                if elem.has_latest_message():
                    # Set the data age to now and reaction time to previous data age value, since we are at the start of the chain
                    message.add_entry(Entry(self.now, elem.get_latest_message().get_entries()[0].data_age, history))
                else:
                    # Set initial value of first message
                    message.add_entry(Entry(self.now, self.now, history))
            else:
                # If we have subscription dependencies, collect all entries
                for forward_message in elem.forward_messages:
                    for entry in forward_message.entries:
                        message.add_entry(
                            Entry(entry.data_age, entry.reaction_time, entry.history))
                elem.forward_messages.clear()
                # Extend history
                message.extend_history(
                    self.executor.get_timer_priority(elem))

            self.now += elem.get_wcet()

            # Update the data age of the analysis values given the previous message
            elem.update_analysis_data_age(self.now)
            # Set the newest message
            elem.set_latest_message(message)
            # Add register entries and update data age and reaction time
            elem.update_register_entries(message)
            elem.update_register_data_age(message)
            elem.update_register_reaction_time(message)
            # Update analysis values for data age and reaction time
            elem.update_analysis_reaction_time(self.now)
            elem.update_analysis_data_age(self.now)

            if self.sim_time:
                sleep(elem.get_wcet())

            # Publish to subscriptions by copying to their DDS buffers
            if elem.get_pub_topic() != "":
                topic = elem.get_pub_topic()
                publish_message = Message()
                for entry in elem.register:
                    publish_message.add_entry(Entry(entry.data_age,entry.reaction_time,entry.history))
                subscription: Subscription
                for subscription in self.executor.get_subscriptions():
                    if subscription.sub_topic == topic:
                        subscription.receive_dds_message(publish_message)

    # Print Functions

    def print_node_states(self):
        """Print data from nodes"""
        nodes = self.executor.get_nodes()
        for node in nodes:
            print("Timers")
            for elem in node.get_timer_list():
                print(elem.register)
            print("Subscriptions")
            for elem in node.get_subscription_list():
                print(elem.register)

    def print_analysis(self):
        """Print analysis data from nodes"""
        nodes = self.executor.get_nodes()
        node: Node
        for node in nodes:
            elem: Subscription
            for elem in node.get_subscription_list():
                if elem.type == "actuator":
                    elem.print_analysis()
            elem: Timer
            for elem in node.get_timer_list():
                if elem.type == "actuator":
                    elem.print_analysis()

    def simulate_time(self, simulate_time_bool):
        """Simulate execution time with sleep"""
        self.sim_time = simulate_time_bool

    def extend_chains(self, chains):
        """Extend chains starting from timer callbacks"""
        # For every chain, extend it
        for _ in range(len(chains)):
            # Remove each element until each chain has been exteneded
            chain = chains.pop(0)
            # If the last element of the current chain is not an actuator, it needs to be extended
            if chain[-1].type != "actuator":
                # Determine all new chains for each subscription and dependency
                new_chains = []
                for subscription in self.executor.get_subscriptions():
                    if subscription.sub_topic == chain[-1].pub_topic:
                        new_chain = chain.copy()
                        new_chain.append(subscription)
                        new_chains.extend(self.extend_chains([new_chain]))
                    if chain[-1] in subscription.subscription_dependencies:
                        new_chain = chain.copy()
                        new_chain.append(subscription)
                        new_chains.extend(self.extend_chains([new_chain]))
                for tmr in self.executor.get_timers():
                    if chain[-1] in tmr.subscription_dependencies:
                        new_chain = chain.copy()
                        new_chain.append(tmr)
                        new_chains.extend(self.extend_chains([new_chain]))
                # Add the new chains to the chains list
                chains.extend(new_chains)
            # If the element is an actuator, return the chain as a list for the extension
            else:
                chains.append(chain)
                return chains
        # Return all chains
        return chains

    def determine_chains(self):
        """Create starting chains from timer callbacks"""
        chains = []
        for timer in self.executor.get_timers():
            if timer.type == "sensor":
                chain = [timer]
                chains.append(chain)
        return self.extend_chains(chains)

    def calculate_upper_bounds(self):
        """Calculate upper bound of chains"""
        chains = self.determine_chains()
        # Determine WCET of all callbacks
        wcet_sum = round(sum([timer.wcet for timer in self.executor.get_timers(
        )])+sum([sub.wcet for sub in self.executor.get_subscriptions()]), 1000)
        for chain in chains:
            upper_bound = 0
            tmr = chain[0]
            upper_bound += tmr.period+wcet_sum-tmr.wcet+wcet_sum
            for elem in chain[1:]:
                if isinstance(elem, Subscription):
                    if elem.get_pub_topic() == "":
                        # For passive subscriptions or actuators
                        upper_bound += wcet_sum  # * elem.buffer_size
                    else:
                        if elem.has_subscription_dependencies():
                            # For trigger subscriptions and filters
                            if chain[chain.index(elem)-1] in elem.get_subscription_dependencies():
                                # Trigger subscription with passive subscription
                                timer_chain = [
                                    ch for ch in chains if elem in ch and ch[ch.index(elem)-1].pub_topic != ""][0]
                                timer_chain_end = timer_chain[max([timer_chain.index(el) for el in timer_chain if isinstance(
                                    el, Timer) and timer_chain.index(el) < timer_chain.index(elem)]):timer_chain.index(elem)+1]
                                chain_tmr = timer_chain_end[0]
                                upper_bound += chain_tmr.period-chain_tmr.wcet+2*wcet_sum
                                for _ in timer_chain_end[1:]:
                                    upper_bound += wcet_sum
                            else:
                                # Trigger subscription only
                                upper_bound += wcet_sum
                        else:
                            # Filter
                            upper_bound += wcet_sum  # * elem.buffer_size
                if isinstance(elem, Timer):
                    upper_bound += elem.period + wcet_sum-elem.wcet+wcet_sum

            print("Upper bound:",round(upper_bound, 10), "Chain:", [self.executor.get_priority(elem) for elem in chain])