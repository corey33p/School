using namespace std;
#include <iostream>
#include "Matrix.h"

Executive::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
    }
    int size;
    while (file >> size) {
        Matrix m = Matrix(file,size);
        double determinant = m.det();
        m.printMatrix();
        cout<<"determinant: "<<determinant<<endl;
    }
}

Executive::~Executive(){}
