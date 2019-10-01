import json
import random
import os

class Hat:
    def __init__(self, parent):
        self.parent = parent
        self.load_probabilities()
        self.compute_probability_range()
        self.add_slots(len(self.parent.picture_object.questions_list))
    def jsonKeys2int(self,x):
        if isinstance(x, dict):
                return {int(k):v for k,v in x.items()}
        return x
    def load_probabilities(self):
        if os.path.isfile("source/probabilities.json"):
            with open("source/probabilities.json","r") as f:
                self.probabilities = json.load(f)
            self.probabilities = self.jsonKeys2int(self.probabilities)
        else:
            answers = [i for i in os.listdir('material/answers') if '.jpg' in i]
            number_of_answers = len(answers)
            self.probabilities={}
            for i in range(number_of_answers):
                self.probabilities[str(i+1)]=1
            self.save_probabilities()
    def save_probabilities(self):
        with open("source/probabilities.json","w") as f:
            json.dump(self.probabilities, f, sort_keys=True, indent=4, separators=(',', ': '))
    def reduce_probability(self):
        index = self.parent.picture_object.current_image_index
        if self.probabilities[index] > 1/100:
            self.probabilities[index] = self.probabilities[index]/2
        self.save_probabilities()
        self.compute_probability_range()
        self.parent.display.update_probability_entry()
    def increase_probability(self):
        index = self.parent.picture_object.current_image_index
        if self.probabilities[index] < 100:
            self.probabilities[index] = self.probabilities[index]*2
        self.save_probabilities()
        self.compute_probability_range()
        self.parent.display.update_probability_entry()
    def compute_probability_range(self):
        self.probability_range = sum(list(self.probabilities.values()))
    def select(self):
        selection = random.uniform(0,self.probability_range)
        index = 0
        while selection > 0: 
            selection-=self.probabilities[index+1]
            index += 1
        print("random selection: " + str(index))
        self.parent.picture_object.go_to_image(index)
    def add_slots(self,target_size):
        number_of_slots = len(self.probabilities)
        if number_of_slots < target_size:
            while number_of_slots < target_size:
                self.probabilities[number_of_slots+1] = 1.0
                number_of_slots += 1
            self.save_probabilities()
            self.compute_probability_range()