#include <iostream>
#include "Executive.h"
#include "Stack.h"
#include "Subprocess.h"
#include "Processor.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    Executive exec;
    exec.run(argv);
    return(0);
}
