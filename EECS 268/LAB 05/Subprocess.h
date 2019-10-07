#ifndef SUBPROCESS_H
#define SUBPROCESS_H

using namespace std;
#include <iostream>
#include <string>

class Subprocess{
    private:
        string name;
        bool canHandleExceptions;
    public:
        Subprocess();
        Subprocess(std::string nam,bool canHandleExceptions);
        virtual ~Subprocess();
        string getName();
        bool getcanHandleExceptions();
};

#endif
