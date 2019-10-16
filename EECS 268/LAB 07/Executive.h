/*
@author - Corey Anderson
@file - Field.h
@date - 10/12/2019
@brief - Simple executive object which will initiate the file stream
and pass it to the Field object, which handles the game.
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
