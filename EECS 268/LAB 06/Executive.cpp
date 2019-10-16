/*
@author - Corey Anderson
@file - Executive.cpp
@date - 10/12/2019
@brief - A simple executive object that will instantiate the matrix
         and evaluate the determinant.
*/

using namespace std;
#include <iostream>
#include "Executive.h"
#include "Matrix.h"

Executive::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
    }
    int size;
    while (file >> size) {
        Matrix* m = new Matrix(file,size);
        double determinant = m->det();
        m->print();
        cout<<"determinant: "<<determinant<<endl;
        delete m;
    }
}

Executive::~Executive(){}
