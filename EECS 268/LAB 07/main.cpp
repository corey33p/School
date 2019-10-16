/*
@author - Corey Anderson
@file - Main.cpp
@date - 10/12/2019
@brief - To solve the following puzzle: You are in a tank traveling up,
down, left, right and diagonally
through electric fields. If you travel
through two minus signs in a row,
your battery is drained and you are stuck. If you
travel through two plus signs in a row, your
battery overcharges and explodes. How can you
travel from start (S) to end (E) through every
cell once and survive?

Inputs presented in txt files as follows:
-   +   -   +   -
+   +   -   -   +
-   +   +   +   S
-   +   E   -   -
-   +   +   -   +

And solutions will be presented as:
Solution:
  16  13  14   3   2
  17  15  12   4   1
  18  19   5  11   S
  20  21   E   6  10
  22  23   7   8   9
*/

#include <iostream>
#include "Executive.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    Executive exec(argv[1]);
    return(0);
}
