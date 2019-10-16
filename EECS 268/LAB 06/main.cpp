/*
@author - Corey Anderson
@file - main.cpp
@date - 10/12/2019
@brief - Evaluate determinants of matrices via a recursive method.
*/

#include <iostream>
#include "Executive.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    {Executive exec(argv[1]);}
    return(0);
}
