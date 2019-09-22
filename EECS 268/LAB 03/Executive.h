#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "ShapeContainer.h"

class Executive
{
    public:
        Executive();
        virtual ~Executive();
        void parseData(vector<string> txtFileLines);
        void run(int argc, char** argv);
        bool readFile(string fileName,vector<string> &lines);
        void doCommand(ShapeContainer &container, string command, int index, string shapeType, double param1, double param2); 
};

#endif
