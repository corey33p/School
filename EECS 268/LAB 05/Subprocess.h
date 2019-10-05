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
        Subprocess(std::string name);
        virtual ~Subprocess();
        string getName();
        bool getcanHandleExceptions();
};

#endif
