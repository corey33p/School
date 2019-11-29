/*
@author - Corey Anderson
@file - main.cpp
@date - 11/29/2019
@brief - Will manage a priority queue of service requests to fix power stations.
*/

#include <iostream>
#include "Executive.h"
#include "Heap.h"
#include "Request.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    Executive<Request> exec(argv[1]);
    return(0);
}
