/*
@author - Corey Anderson
@file - main.cpp
@date - 9/23/2019
@brief - Program will process an array of shapes, created under an interface
shape class. Data will be imported from a text file for parameters of shapes
to be created, and information will be printed to the console as also specified
in the input file. Details at
https://wiki.ittc.ku.edu/ittc_wiki/index.php/EECS268:Lab
*/

#include <iostream>
#include "Executive.h"

using namespace std;

int main(int argc, char** argv) {
	if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
        // system("pause");
		exit(1);
	}
    Executive exec;
    exec.run(argc,argv);
    // system("pause");
    return(0);
}
