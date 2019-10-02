/*
@author - Corey Anderson
@file - main.cpp
@date - 10/1/2019
@brief - Program will implement a singly linked list to manage student records.
*/

#include <iostream>
#include "Executive.h"
#include "Student.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 3) {
		cout << "Error, program requires 2 argument." << endl;
		exit(1);
	}
    Executive<Student> exec;
    exec.run(argv);
    return(0);
}
