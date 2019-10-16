/*
@author - Corey Anderson
@file - Executive.h
@date - 10/12/2019
@brief - A simple executive object that will instantiate the matrix
         and evaluate the determinant. 
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

class Executive{
    public:
        Executive(std::string fileName);
        virtual ~Executive();
};

#endif
