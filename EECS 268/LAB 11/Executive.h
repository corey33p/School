/*
@author - Corey Anderson
@file - Executive.h
@date - 11/29/2019
@brief - Executive object will process an input file with commands
which will be handled by a priority queue which will use a max heap backend.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

template<class ItemType>
class Executive{
    public:
        Executive(std::string fileName);
        virtual ~Executive();
    private:
        /*
        @pre - Will receive a line by reference from the text file to parse
        @post - Will parse the first word from the line, removing it from the line
        @return - Will return the first word in the line
        */
        std::string popWord(std::string& line);

        /*
        @pre - Will receive a priority queue "BY VALUE"
        @post - The remaining items in the priority queue will be printed
        @return - void
        */
        void showStatus(PriorityQueue<ItemType> pq);
};

#endif
