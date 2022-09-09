"""Executor class"""

from node import Node
from timer import Timer
from subscription import Subscription

class Executor:
    """Executor class"""
    nodes = 0

    timer_list = 0
    subscription_list = 0

    identifier = 0
    node_id = 0
    timer_id = 0
    subscription_id = 0

    def __init__(self):
        self.nodes = []
        self.timer_list = []
        self.subscription_list = []

        self.identifier = 0
        self.node_id = 0
        self.timer_id = 0
        self.subscription_id = 0

    def add_timers(self, timer_list):
        """Add timers from list to executor"""
        for timer in timer_list:
            self.timer_list.append(timer)
            timer.set_id(self.timer_id)
            self.timer_id += 1

    def add_subscriptions(self, subscription_list):
        """Add subscriptions from list to executor"""
        for subscription in subscription_list:
            self.subscription_list.append(subscription)
            subscription.set_id(self.subscription_id)
            self.subscription_id += 1

    def get_priority(self,elem):
        """Get callback prioritiy"""
        if isinstance(elem,Timer):
            return self.get_timer_priority(elem)
        elif isinstance(elem,Subscription):
            return self.get_subscription_priority(elem)

    def get_timer_priority(self, timer):
        """Get timer priority"""
        if timer in self.timer_list:
            return timer.get_id()
        else:
            print("timer not found")

    def get_subscription_priority(self, subscription):
        """Get subscription priority"""
        if subscription in self.subscription_list:
            return subscription.get_id()+self.timer_id
        else:
            print("subscription not found")

    def add_node(self, node:Node):
        """Add node to executor"""
        self.nodes.append(node)
        node.set_id(self.node_id)
        self.node_id += 1

        self.add_timers(node.get_timer_list())
        self.add_subscriptions(node.get_subscription_list())

    def get_nodes(self):
        """Return nodes"""
        return self.nodes

    def get_timers(self):
        """Return timers"""
        return self.timer_list

    def get_subscriptions(self):
        """Return subscriptions"""
        return self.subscription_list
