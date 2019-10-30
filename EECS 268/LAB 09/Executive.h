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
    private:
        void generate(int n);
        double* theList;
        int size;
        void printList();
};

#endif
