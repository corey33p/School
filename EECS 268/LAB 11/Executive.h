#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

template<class ItemType>
class Executive{
    public:
        Executive(std::string fileName);
        virtual ~Executive();
    private:
        std::string popText(std::string& line);
};

#endif
