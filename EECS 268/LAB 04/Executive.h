/*
@author - Corey Anderson
@file - Executive.h
@date - 9/23/2019
@brief - This will serve as a parent object, which will import data from
a file and create the ShapeContainer data structure, which will handle all the
individual shapes.
*/

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

        /*
        @preconditions - a vector of lines from the text file will already be
        @postconditions - text file lines will be processed one by one, and
        commands will be passed to doCommand(...) accordingly. parseData is
        the last function called in run(...). When parseData
        has finished, the program will be finished.
        @return - is a void function
        */
        void parseData(vector<string> txtFileLines);

        /*
        @preconditions - arguments which have been supplied at the terminal
        will be supplied. run(...) will call appropriate functions to read
        the input file, parse the file, and execute commands.
        @postconditions - When run(...) has finished, the program will terminate.
        @return - is a void function
        */
        void run(int argc, char** argv);

        /*
        @preconditions - The name of the file will be recieved from the terminal
        @postconditions - The input file will be read.
        @return - A boolean value will be returned to indicate that the reading
        of the file has been finished successfully. 
        */
        bool readFile(string fileName,vector<string> &lines);
        void doCommand(ShapeContainer &container, string command, int index, string shapeType, double param1, double param2);
};

#endif
