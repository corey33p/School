import random
import os

def generate(n):
    used_IDs = []
    class_types = {"Freshman","Sophomore","Junior","Senior"}
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    full_string = ""
    for i in range(n):
        # ID
        new_ID = random.randint(100000,999999)
        while new_ID not in used_IDs:
            used_IDs.append(new_ID)
        
        # first name
        first_name_length = 0
        while first_name_length < 2:
            first_name_length = int(abs(random.gauss(6,3)))
        first_name=""
        for i in range(first_name_length):
            first_name += random.choice(alphabet)
            if i == 0: first_name = first_name.upper()
        
        # last name
        last_name_length = 0
        while last_name_length < 2:
            last_name_length = int(abs(random.gauss(5,3)))
        last_name=""
        for i in range(last_name_length):
            last_name += random.choice(alphabet)
            if i == 0: last_name = last_name.upper()
        
        # class
        student_class = random.sample(class_types,1)
        
        # credit hours completed
        credit_hours_completed = 0
        while credit_hours_completed < 12:
            credit_hours_completed = int(random.gauss(100,30))
        
        # grade points earned
        grade_points_earned = credit_hours_completed * 4 + 1
        while grade_points_earned > credit_hours_completed * 4:
            grade_points_earned = int(random.gauss(credit_hours_completed * 4,credit_hours_completed))
        
        line = str(new_ID) + " " + first_name + " " + last_name + " " + str(credit_hours_completed) + " " + str(grade_points_earned) + "\n"
        full_string += line
        
    with open(os.getcwd().replace('\\','/')+'/data.txt',"w") as f:
        f.write(full_string)
