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
