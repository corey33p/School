/*
The processor has a Queue of Stacks of Subprocesses.
A "process" is a Stack of Subprocesses.
*/

#ifndef PROCESSOR_H
#define PROCESSOR_H

using namespace std;
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

template<class ItemType, class ItemType2>
class Processor{
    private:
        Queue<ItemType> queue;
        std::string status;
    public:
        Processor();
        virtual ~Processor();
        void startProcess(std::string name,std::vector<std::string> subprocesses,std::vector<bool> canHandleExceptions);
        void process();
        void throwException();
        void printStatus();
};

#endif
