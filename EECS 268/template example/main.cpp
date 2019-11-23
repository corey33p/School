#include <iostream>
#include "Executive.h"
#include "B.h"

using namespace std;

int main(int argc, char** argv) {
    if( argc != 2) {
		cout << "Error, program requires 1 argument." << endl;
		exit(1);
	}
    Executive<B> exec;
    return(0);
}