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
        static void visit(ItemType&);
        virtual ~Executive();
        void readFile();
        void parseLine();
    private:
        std::string popText(std::string& line);
};

#endif

// template class BinaryNode<Pokemon>;
