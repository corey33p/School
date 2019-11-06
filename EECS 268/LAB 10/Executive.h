/*
@author - Corey Anderson
@file - Executive.h
@date - 10/26/2019
@brief - Executive object is minimal. It will take the file input and pass it
to an object which will execute and solve the blob puzzle.
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
