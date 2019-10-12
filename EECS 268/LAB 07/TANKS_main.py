'''Lab 7: Driving a tank through electric fields
This lab project will be to develop a recursive backtracking solution 
to solve the problem illustrated and explained in the image on the right. 
Your program will read the description of an electric field from a file. 
The first two numbers in the file are the number of rows and columns in 
the grid. The remainder of the file will contain the (nRows * nCols) 
non-blank characters as indicated in the figure on the right. There must 
be exactly one 'S' and exactly one 'E'.

Not all electric fields will have a solution. Moreover, a given electric 
field may have multiple solutions. Like all backtracking algorithms, you 
select candidate solutions for each successive sub-problem (here, for 
the sub-problem of where to go next). The order in which you test 
candidate solutions affects the solution you find in instances where 
multiple solutions are possible. To produce the results shown below, you 
must test candidate solutions in the order shown on the right. The blank 
square denotes the current cell; candidate "next" cells are to be examined 
in the order indicated.

Sample Program Executions
$ ./lab07 ElectricField3.txt 
Electric Field as read:
   -   +   -   +   -
   +   +   -   -   +
   -   +   +   +   S
   -   +   E   -   -
   -   +   +   -   +
Solution:
  16  13  14   3   2
  17  15  12   4   1
  18  19   5  11   S
  20  21   E   6  10
  22  23   7   8   9
$
$ ./lab07 ElectricField5.txt 
Electric Field as read:
   -   +   -   +   -
   +   +   -   +   +
   -   +   +   +   S
   -   +   E   +   -
   -   +   +   -   +
No solution possible.
$
Notice the spacing when printing the electric fields. I used a field width of 
4 under the assumption that electric fields we test will not be more than 30x30, 
hence the numbers won't need more than 3 digits. Use that same spacing when 
implementing your printing.

Two Quick Design Notes
Since there is essentially nothing for an "Executive" to do in this project (e.g., 
no interactive dialog), it will be sufficient for your main program to simply 
create a class representing an electric field, call its print method, call some 
sort of "traverse" or "solve" method, and then call the print method again. Assuming you pass the file name to the electric field class constructor, main shouldn't require more than a half dozen lines or so.
As with the Matrix lab, you must dynanically allocate storage for each electric 
field instance that is exactly the size needed. You have the same two basic choices 
as in the Matrix lab.

Grading Criteria
Grades will be assigned according to the following criteria:

Laboratory 6
Our usual minimal main program: 5%
Reasonable design and correct implementation of class Executive: 15%
Correct implementation and usage of the class Matrix constructor that creates Sr, c: 20%
Correct implementation of the Matrix::det: 20%
Reasonable design and correct implementation of all other aspects ofclass Matrix: 15%
Output (formatting, clarity): 15%
No memory leaks: 10%
Laboratory 7
Electric Field: Overall class design: 25%
Electric Field: Parsing and storage of the field: 25%
Electric Field: Correct implementation of the solve or traverse method: 35%
Electric Field: Print method: 10%
Fairly minimal main: 5%
'''

import os
import win32gui
import win32con
import numpy as np

class TANKS:
    def __init__(self):
        data = list(self.loadFile("t6.txt"))
        rows,cols=data.pop(0),data.pop(0)
        ar = np.asarray(data)
        ar = ar.reshape(rows,cols)
        self.solve_step(np.copy(ar),original=True)
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
        if not filename: filename = input('In which file is the tanks data located? ')
        while (os.path.isfile(filename) == False):
            print('\nNot a valid filename. Press 1 to view files to choose from or 2 to enter a new filename:\n')
            choice = input('1 or 2? ')
            while (choice != '1') and (choice != '2'):
                choice = input("Choose '1' or '2': ")
            if choice == '1':
                self.printoptions()
                filename = input('In which file is the tanks data located? ')
            elif choice == '2': filename = input('\nIn which file is the tanks data located? ')
        with open(filename, 'r') as file:
            data = file.read().replace('\n', ' ')
            while "  " in data: data.replace("  "," ")
        data = data.split(" ")
        def replace(element):
            if element == "+": return 1
            elif element == "-": return 0
            elif element in {"S","s"}: return 2
            elif element in {"E","e"}: return 3
            else: return int(element)
        data = [replace(item) for item in data]
        return data
    def solve_step(self,m,steps=None,original=False):
        # print("\nm:\n" + str(m))
        # print("steps:\n" + str(steps))
        def neighbors(steps):
            last_step = int(np.max(steps))
            last_row,last_col = np.argwhere(steps == last_step)[0]
            for row in range(last_row+1,last_row-2,-1):
                for col in range(last_col-1,last_col+2):
                    if (row >= 0) and (row < steps.shape[0]):
                        if (col >= 0) and (col < steps.shape[1]):
                            if (row != last_row) or (col != last_col):
                                yield row,col
        if steps is None:
            row,col = np.argwhere(m==2)[0]
            steps = np.zeros((m.shape),np.int32)
            steps[row,col]=1
        
        previous_step = int(np.max(steps))
        row,col = np.argwhere(steps==previous_step)[0]
        previous_val = m[row,col]
        solution = None
        for neighbor in neighbors(steps):
            # print("neighbor: " + str(neighbor))
            if steps[neighbor] == 0:
                # print("m[neighbor]: " + str(m[neighbor]))
                if m[neighbor] == 3:
                    if previous_step == m.size-1:
                        steps[neighbor]=previous_step+1
                        print("solution:\n" + str(steps))
                        solution = steps
                elif m[neighbor] == 1:
                    if previous_val in (0,2):
                        steps[neighbor]=previous_step+1
                        solution = self.solve_step(np.copy(m),np.copy(steps))
                        steps[neighbor]=0
                elif m[neighbor] == 0:
                    if previous_val in (1,2):
                        steps[neighbor]=previous_step+1
                        solution = self.solve_step(np.copy(m),np.copy(steps))
                        steps[neighbor]=0
            if solution is not None:
                return solution
        if original: print("Found no solution.")
        return None

if __name__ == '__main__':
    main_object = TANKS()
    