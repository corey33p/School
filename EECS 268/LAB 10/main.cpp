/*
@author - Corey Anderson
@file - main.cpp
@date - 11/20/2019
@brief - Program will use a binare search tree to store and manage pokedex entries.
*/



#include <iostream>
#include "Executive.h"
#include "Pokemon.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    Executive<Pokemon> exec(argv[1]);
    return(0);
}
