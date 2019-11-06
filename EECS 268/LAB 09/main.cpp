#include <iostream>
#include "Executive.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 5) {
		cout << "Error, program requires 4 arguments" << endl;
		exit(1);
	}
    Executive exec(argv[1],argv[2],argv[3],argv[4]);
    return(0);
}
