using namespace std;
#include <iostream>
#include "Executive.h"
#include "Field.h"

Executive::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
    }
    int rows;
    int cols;
    file >> rows;
    file >> cols;
    Field f = Field(file,(int)rows,(int)cols);
    cout<<"Electric Field as read:"<<endl;
    f.printField();
    f.start();
    f.printSteps();
}

Executive::~Executive(){}
