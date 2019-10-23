import numpy as np
import os

class TANKS:
    def __init__(self):
        data = self.loadFile('f1.txt')
        self.size=[self.rows,self.cols]
        ar = np.asarray(data)
        ar = ar.reshape(self.rows,self.cols)
        print("ar:\n"+str(ar))
        self.solve_step(ar,self.bRow,self.bCol)
    def printoptions(self):
        all = os.listdir()
        index = 0
        print('\n')
        while index < len(all):
            if os.path.isfile(all[index]):
                    print(all[index])
            index = index + 1
        print('\n')
    def loadFile(self,filename):
        if not filename: filename = input('In which file is the blob data located? ')
        while (os.path.isfile(filename) == False):
            print('\nNot a valid filename. Press 1 to view files to choose from or 2 to enter a new filename:\n')
            choice = input('1 or 2? ')
            while (choice != '1') and (choice != '2'):
                choice = input("Choose '1' or '2': ")
            if choice == '1':
                self.printoptions()
                filename = input('In which file is the blob data located? ')
            elif choice == '2': filename = input('\nIn which file is the tanks data located? ')
        with open(filename, 'r') as file:
            data = file.read()
        def replace(element):
            if element == "#": return 1
            elif element == " ": return 0
            else: return element
        print("data: "+str(data))
        self.rows,self.cols=int(data[0]),int(data[2])
        data=data[4:]
        self.bRow,self.bCol=int(data[0]),int(data[2])
        data=data[4:]
        data = data.split("\n")
        data = list(filter(lambda a: a != "", data))
        for j,item in enumerate(list(data)):
            new_row = []
            for i,character in enumerate(item):
                new_row.append(replace(character))
            data[j]=new_row
        return data
    def solve_step(self,m,curRow,curCol):
        print("current position: "+str(curRow)+", "+str(curCol))
        possible_steps = [[curRow-1,curCol],[curRow+1,curCol],[curRow,curCol-1],[curRow,curCol+1]]
        bad_steps = []
        for step in list(possible_steps):
            bad_step=False
            for i,coordinate in enumerate(step):
                if coordinate<0:
                    bad_step = True
                elif coordinate>self.size[i]-1:
                    bad_step = True
            bad_steps.append(bad_step)
        possible_steps = [possible_steps[i] for i in range(4) if not bad_steps[i]]
        print("possible_steps: "+str(possible_steps))
        

if __name__ == '__main__':
    main_object = TANKS()
