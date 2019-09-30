#include <iostream>
#include "Executive.h"
#include "Student.h"

using namespace std;

int main() {
    Executive<Student> exec;
    exec.run(cin,cin);
    system("pause");
    return(0);
}
