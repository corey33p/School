/*
@author - Corey Anderson
@file - Field.cpp
@date - 10/12/2019
@brief - Simple executive object which will initiate the file stream
and pass it to the Field object, which handles the game.
*/

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
    Field* f = new Field(file,(int)rows,(int)cols);
    cout<<"Electric Field as read:"<<endl;
    f->printField();
    f->start();
    delete f;
}

Executive::~Executive(){}
