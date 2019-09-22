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
