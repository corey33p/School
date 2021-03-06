#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

class Executive{
    public:
        Executive(std::string labNumber, std::string listSize, std::string initMethod,std::string sortType);
        virtual ~Executive();
    private:
        void generate(int n);
        double* theList;
        bool listExists = false;
        int size;
        void printList();
        void reverseList(double arr[], int start, int end);
        double sort(int count,std::string state,std::string method);
        void robotSort();
};

#endif
