"""Subscription class"""

from message import Message
from entry import Entry

class Subscription:
    """Subscription class"""
    type = 0
    identifier = 0

    wcet = 0

    sub_topic = 0
    pub_topic = 0

    dds_buffer = 0
    buffer_size = 0

    latest_message = 0
    forward_messages = 0
    subscription_dependencies = 0
    subscription_forwards = 0

    register = 0
    analysis_register = 0

    def __init__(self, wcet, buffer_size, sub_topic, pub_topic, type_name):
        # Type Name
        self.type = type_name
        self.identifier = 0
        # Execution time
        self.wcet = wcet
        # Subscribed and Published Topic
        self.sub_topic = sub_topic
        self.pub_topic = pub_topic
        # Buffer Values
        self.dds_buffer = []
        self.buffer_size = buffer_size
        # Latest Message
        self.latest_message = None
        self.forward_messages = []
        self.subscription_dependencies = []
        self.subscription_forwards = []
        # Register
        self.register = []
        self.analysis_register = []

    # DDS Messages

    def receive_dds_message(self, message:Message):
        """Receive message for buffer"""
        # self.dds_buffer.append(message)
        # if len(self.dds_buffer) > self.buffer_size:
        #     print("Warning, buffer overflow of", len(self.dds_buffer)-self.buffer_size ,"for", self.type,"of topic",self.sub_topic)
        #FIFO
        if len(self.dds_buffer) == self.buffer_size:
            self.dds_buffer = self.dds_buffer[1:]
            self.dds_buffer.append(message)
            print("Warning, buffer for", self.type,"of topic",self.sub_topic,"dropped a message")
        else:
            self.dds_buffer.append(message)

    def has_dds_messages(self):
        """Returns if buffer non-empty"""
        return len(self.dds_buffer)>0

    # Latest Message

    def get_newest_buffer(self):
        """Returns newest buffer element"""
        return self.dds_buffer[0]

    def advance_buffer(self):
        """Removes first element"""
        self.dds_buffer = self.dds_buffer[1:]

    def set_latest_message(self, message):
        """Set latest message"""
        self.latest_message = message

    def has_latest_message(self):
        """Check if latest message available"""
        return self.latest_message is not None

    def get_latest_message(self):
        """Get latest message"""
        return self.latest_message

    # Subscription Dependencies

    def get_subscription_dependencies(self):
        """Get subscription dependencies"""
        return self.subscription_dependencies

    def has_subscription_dependencies(self):
        """Check if subscription dependencies available"""
        return len(self.subscription_dependencies)>0

    def add_subscription_dependency(self, subscription):
        """Add subscription dependencies"""
        self.subscription_dependencies.append(subscription)

    # Subscription Forwards

    def get_subscription_forwards(self):
        """Get subscription forwards"""
        return self.subscription_forwards

    def has_subscription_forwards(self):
        """Check if subscription forwards available"""
        return len(self.subscription_forwards)>0

    def add_subscription_forward(self, subscription):
        """Add subscription forwards"""
        self.subscription_forwards.append(subscription)

    # Register

    def update_register_entries(self):
        """Add register entries from latest message"""
        entry:Entry
        for entry in self.latest_message.entries:
            if not any(elem.history == entry.history for elem in self.register):
                self.register.append(Entry(entry.data_age,entry.reaction_time,entry.history))

    def update_register_reaction_time(self):
        """Update existing register entries reaction time using latest message"""
        entry:Entry
        for entry in self.latest_message.entries:
            existing_entry:Entry
            existing_entry = next(item for item in self.register if item.history == entry.history)
            existing_entry.reaction_time = entry.reaction_time

    def update_register_data_age(self):
        """Update existing register entries data age using latest message"""
        entry:Entry
        for entry in self.latest_message.entries:
            existing_entry:Entry
            existing_entry = next(item for item in self.register if item.history == entry.history)
            existing_entry.data_age = entry.data_age

    def get_register(self):
        """Get message register"""
        return self.register

    def get_analysis_register(self):
        """Get analysis register"""
        return self.analysis_register

    # Analysis Values

    def update_analysis_reaction_time(self,now):
        """Update analysis register reaction time"""
        entry:Entry
        for entry in self.register:
            if not any(elem.history == entry.history for elem in self.analysis_register):
                self.analysis_register.append(Entry(now-entry.data_age,now-entry.reaction_time,entry.history))
            else:
                analysis_entry:Entry
                analysis_entry = next(item for item in self.analysis_register if item.history == entry.history)
                if analysis_entry.reaction_time < now-entry.reaction_time:
                    analysis_entry.reaction_time = now-entry.reaction_time

    def update_analysis_data_age(self,now):
        """Update analysis register data age"""
        entry:Entry
        for entry in self.register:
            if not any(elem.history == entry.history for elem in self.analysis_register):
                self.analysis_register.append(Entry(now-entry.data_age,now-entry.reaction_time,entry.history))
            else:
                analysis_entry:Entry
                analysis_entry = next(item for item in self.analysis_register if item.history == entry.history)
                if analysis_entry.data_age < now-entry.data_age:
                    analysis_entry.data_age = now-entry.data_age

    def print_analysis(self):
        """Print analysis values"""
        print("Analysis for Subscription ","->",self.get_sub_topic(),"->",self.get_pub_topic())
        # for elem in self.register:
        #     print(elem)
        for elem in self.analysis_register:
            print(elem)

    # Other Values

    def get_pub_topic(self):
        """Get publisher topic"""
        return self.pub_topic

    def get_sub_topic(self):
        """Get subscription topic"""
        return self.sub_topic

    def get_type(self):
        """Get type"""
        return self.type

    def get_wcet(self):
        """Get wcet"""
        return self.wcet

    def get_id(self):
        """Get identifier"""
        return self.identifier

    def set_id(self,new_id):
        """Set wcet"""
        self.identifier = new_id

    def __repr__(self):
        return str(["subscription",self.sub_topic,self.pub_topic])
    def __str__(self):
        return str(["subscription",self.sub_topic,self.pub_topic])
        