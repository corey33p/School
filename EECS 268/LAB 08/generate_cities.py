import numpy as np
import os
import random

def generate():
    city_size = np.random.normal(5,5,2)
    city_size[city_size < 2]=(2+(2 - city_size))[city_size < 2]
    city_size = city_size.astype(np.uint8)
    
    sewer_chance = .08
    building_chance = .58 # minus sewer_chance
    
    random_uniform = np.random.random(city_size)
    
    city = np.zeros(city_size)
    city[random_uniform < building_chance]=1
    city[random_uniform < sewer_chance]=2
    city = city.astype(np.int32)
    return city

done=False
while not done:
    city = generate()
    print("\n-----------\nnew city:\n" + str(city))
    choice = input("Save city? y/n -> ")
    choice = choice.lower()
    if choice == "y":
        start_point = random.choice(np.argwhere(city == 0))
        file_index=0
        while os.path.isfile(os.getcwd().replace('\\','/')+"/f"+str(file_index)+".txt"):
            file_index += 1
        fname=os.getcwd().replace('\\','/')+"/f"+str(file_index)+".txt"
        file_string = str(city.shape[0])+" "+str(city.shape[1])+"\n"+str(start_point[0])+" "+str(start_point[1])+"\n"
        for row in range(city.shape[0]):
            for col in range(city.shape[1]):
                if city[row,col]==0: file_string+= " "
                elif city[row,col]==1: file_string += "#"
                elif city[row,col]==2: file_string += "@"
            file_string += "\n"
        with open(os.getcwd().replace('\\','/')+"/f"+str(file_index)+".txt","w") as f:
            f.write(file_string)
        done_input = input("Done? y/n -> ")
        done_input = done_input.lower()
        if done_input == "y": done = True

