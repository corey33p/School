#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"

template<class ItemType>
class Executive{
    public:
        Executive();
        virtual ~Executive();
        bool readFile(std::string fileName,vector<std::string> &lines);
        void run(char** argv);
        void parseLine(std::vector<std::string>& subprocesses, std::vector<bool>& canHandle);
        string popWord(string& line);
};

#endif
