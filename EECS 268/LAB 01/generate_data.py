import random
import os
number_of_lines = 0
while number_of_lines < 12:
    number_of_lines = int(abs(random.gauss(100,200)))

the_str = str(number_of_lines)+"\n"
alphabet = 'abcdefghijklmnopqrstuvwxyz'
for h in range(number_of_lines):
    first_name_length = 0
    while first_name_length < 2:
        first_name_length = int(abs(random.gauss(5,3)))
    first_name=""
    for i in range(first_name_length):
        first_name += random.choice(alphabet)
        if i == 0: first_name = first_name.upper()
    the_str += first_name
    spaces = 8-first_name_length%8
    # print("first_name: " + str(first_name))
    # print("first_name_length: " + str(first_name_length))
    # print("first_name_length%8: " + str(first_name_length%8))
    # input("spaces: " + str(spaces))
    for space in range(spaces):
        the_str += " "
    #
    last_name_length = 0
    while last_name_length < 2:
        last_name_length = int(abs(random.gauss(5,3)))
    last_name=""
    for i in range(last_name_length):
        last_name += random.choice(alphabet)
        if i == 0: last_name = last_name.upper()
    the_str += last_name
    spaces = 8-last_name_length%8
    for space in range(spaces):
        the_str += " "
    #
    team_len = 3
    team = ''
    for i in range(team_len):
        team += random.choice(alphabet)
    team = team.upper()
    the_str += team
    spaces = 8-team_len%8
    for space in range(spaces):
        the_str += " "
    #
    bye_week = random.randint(0,20)
    bye_week = str(bye_week)
    the_str += bye_week
    spaces = 8-len(bye_week)%8
    for space in range(spaces):
        the_str += " "
    #
    # expert_ranking = random.randint(0,20)
    expert_ranking = h
    expert_ranking = str(expert_ranking)
    the_str += expert_ranking
    spaces = 8-len(expert_ranking)%8
    for space in range(spaces):
        the_str += " "
    #
    personal_tier = random.randint(0,20)
    personal_tier = str(personal_tier)
    the_str += personal_tier
    spaces = 8-len(personal_tier)%8
    for space in range(spaces):
        the_str += " "
    the_str += "\n"

with open(os.getcwd().replace('\\','/')+'/data.txt',"w") as f:
    f.write(the_str)
