"""Message class"""

from entry import Entry

class Message:
    """Message class"""
    entries = []

    def __init__(self):
        self.entries = []

    def add_entry(self,entry):#
        """Add entry to message"""
        if not entry.history in [elem.history for elem in self.entries]:
            self.entries.append(entry)

    def get_entries(self):
        """Return message entries"""
        return self.entries

    def extend_history(self,elem):
        """Extend history of all entries in message"""
        entry:Entry
        for entry in self.entries:
            entry.extend_history(elem)

    # Print

    def __repr__(self):
        return str([str(elem) for elem in self.entries])
    def __str__(self):
        return str([str(elem) for elem in self.entries])
        