"""Entry for end-to-end measurement"""
class Entry:
    """Entry for end-to-end measurement"""
    history = []
    data_age = 0
    reaction_time = 0

    def __init__(self, data_age, reaction_time, history):
        self.history = list.copy(history)
        self.data_age = data_age
        self.reaction_time = reaction_time

    def update_data_age(self, data_age):
        """Set data age"""
        self.data_age = data_age

    def update_reaction_time(self, reaction_time):
        """Set reaction time"""
        self.reaction_time = reaction_time

    def extend_history(self, elem):
        """Append element to history"""
        self.history.append(elem)

    # Return data

    def get_data_age(self):
        """Get data age"""
        return self.data_age

    def get_reaction_time(self):
        """Get reaction time"""
        return self.reaction_time

    def get_history(self):
        """Get history"""
        return self.history

    # Print

    def __repr__(self):
        return str(["Data Age", round(self.data_age, 10),
                    "Reaction Time", round(self.reaction_time, 10), "Chain:", self.history])

    def __str__(self):
        return str(["Data Age", round(self.data_age, 10),
                    "Reaction Time", round(self.reaction_time, 10), "Chain:", self.history])
