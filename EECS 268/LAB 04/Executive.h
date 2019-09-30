#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
// #include "ListInterface.h"
#include "LinkedList.h"
#include "Student.h"

template<class ItemType>
class Executive{
    public:
        Executive();
        virtual ~Executive();
        void read(std::string studentsFile, LinkedList<ItemType>& list);
        void run(std::istream& students, std::istream& commands);
        bool readFile(string fileName,vector<string> &lines);
        //
        void handleClass(std::string command, LinkedList<ItemType> list);
        void handleDropOut(std::string command, LinkedList<ItemType>& list);
        void handleHonorsGPA(std::string command, LinkedList<ItemType> list);
        void handleNewStudent(std::string command, LinkedList<ItemType>& list);
        void handlePrintAll(LinkedList<ItemType> list);
        void handlePrintStudent(std::string command, LinkedList<ItemType> list);
        
};

#endif

