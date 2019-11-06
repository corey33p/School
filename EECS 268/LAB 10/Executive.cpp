/*
@author - Corey Anderson
@file - Executive.cpp
@date - 10/26/2019
@brief - Executive object is minimal. It will take the file input and pass it
to an object which will execute and solve the blob puzzle.
*/

using namespace std;
#include <iostream>
#include "Executive.h"
#include "City.h"

Executive::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    int rows;
    int cols;
    file >> rows;
    file >> cols;
    int sRow;
    int sCol;
    file >> sRow;
    file >> sCol;
    City* c = new City(file,(int)rows,(int)cols,(int)sRow,(int)sCol);
    cout<<"Input file as read:"<<endl;
    c->printCity();
    c->begin();
    c->printCity();
    delete c;
}

Executive::~Executive(){}
