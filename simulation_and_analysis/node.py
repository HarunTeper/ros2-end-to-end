"""Node class"""

from timer import Timer
from subscription import Subscription


class Node:
    """Node class"""
    name = ""

    subscription_list = []
    timer_list = []

    identifier = 0

    def __init__(self, name):
        self.name = name
        self.subscription_list = []
        self.timer_list = []

        self.identifier = 0

    def add_timer(self, timer: Timer):
        """Add timer to node"""
        self.timer_list.append(timer)

    def add_subscription(self, subscription: Subscription):
        """Add subscription to node"""
        self.subscription_list.append(subscription)

    def insert_subscription(self, position, subscription: Subscription):
        """Insert subscription into list"""
        self.subscription_list.insert(position, subscription)

    def add_sensor(self, phase: int, period: int, wcet: int, buffer_size: int, pub_topic: str):
        """Add sensor callbacks"""
        timer = Timer(phase, period, wcet, buffer_size, pub_topic, "sensor")
        self.add_timer(timer)

    def add_filter(self, wcet: int, buffer_size: int, sub_topic: str, pub_topic: str):
        """Add filter callbacks"""
        subscription = Subscription(
            wcet, buffer_size, sub_topic, pub_topic, "Filter")
        self.add_subscription(subscription)

    def add_timer_fusion(self, wcets: list, buffer_sizes: list, sub_topics: list, phase: int,
                         period: int, wcet: int, buffer_size: int, pub_topic: str):
        """Add timer fusion callbacks"""
        timer = Timer(phase, period, wcet, buffer_size,
                      pub_topic, "timerfusion")
        for i, topic in enumerate(sub_topics):
            subscription = Subscription(
                wcets[i], buffer_sizes[i], topic, "", "timerfusion")
            subscription.add_subscription_forward(timer)
            self.add_subscription(subscription)
            timer.add_subscription_dependency(subscription)
        self.add_timer(timer)

    def add_subscription_fusion(self, wcets: list, buffer_sizes: int,
                                sub_topics: list, pub_topic: str):
        """Add subscription fusion callbacks"""
        subscriptions = []
        for i, topic in list(enumerate(sub_topics)):
            # Create the fusion callback first
            subscription = Subscription(wcets[i], buffer_sizes[i], topic, [
                                        "", pub_topic][i == 0], "subscriptionfusion")
            # For all subscription-only callbacks, add them as a dependency for the fusion callback
            if i > 0:
                subscriptions[0].add_subscription_dependency(subscription)
                subscription.add_subscription_forward(subscriptions[0])
            # Save for registration
            subscriptions.append(subscription)
        # Register in reverse order so that fusion is executed after subscription-only callbacks
        for subscription in reversed(subscriptions):
            self.add_subscription(subscription)

    def add_timer_actuator(self, sub_wcet: int, subbuffer_size: int, sub_topic: str, timer_phase:
                           int, timer_period: int, timer_wcet: int, timerbuffer_size: int):
        """Add timer actuator callbacks"""
        subscription = Subscription(
            sub_wcet, subbuffer_size, sub_topic, "", "actuatorSubscription")
        timer = Timer(timer_phase, timer_period, timer_wcet,
                      timerbuffer_size, "", "actuator")

        timer.add_subscription_dependency(subscription)
        subscription.add_subscription_forward(timer)

        self.add_subscription(subscription)
        self.add_timer(timer)

    def add_subscription_actuator(self, wcet: int, buffer_size: int, sub_topic: str):
        """Add subscription actuator callbacks"""
        subscription = Subscription(
            wcet, buffer_size, sub_topic, "", "actuator")
        self.add_subscription(subscription)

    def get_timer_list(self):
        """Get timer list"""
        return self.timer_list

    def get_subscription_list(self):
        """Get subscription list"""
        return self.subscription_list

    def get_id(self):
        """Get identifier"""
        return self.identifier

    def set_id(self, new_id):
        """Set identifier"""
        self.identifier = new_id
