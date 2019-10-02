/*
@author - Corey Anderson
@file - Executive.h
@date - 10/1/2019
@brief - Will process input files for student data, as well as commands to
handle the data.
*/

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
        
        /*
        @preconditions - LinkedList object will be created and name of student
        data file will be obtained.
        @postconditions - This function will add the student data
        to the linked list.
        @return - void
        */
        void read(std::string studentsFile, LinkedList<ItemType>& list);
        
        /*
        @preconditions - The name of the file containing the commands used
        to manage the student LinkedList will be obtained.
        @postconditions - The file will be read and the commands will be
        placed into a vector of strings.
        @return - std::vector<std::string> containing the commands
        */
        std::vector<std::string> readCommands(std::string commandsFile);
        
        /*
        @preconditions - Command arguments will be received from the main func.
        @postconditions - Program will be finished.
        @return - void
        */
        void run(char** argv);
        
        /* Handles the reading of the file for both readCommands(...) and
        read(...)
        @preconditions - Name of file to be read
        @postconditions - File will be read.
        @return - Returns a boolean value of whether the file was
        successfully read.
        */
        bool readFile(string fileName,vector<string> &lines);
        //
        
        /*
        @preconditions - A string containing the parameters of the command
        will be read. LinkedList of students will exist.
        @postconditions - The specified students in the specified class
        will be printed to the console.
        @return - void
        */
        void handleClass(std::string command, LinkedList<ItemType>& list);
        
        /*
        @preconditions - A string containing the ID of the student which
        is dropping out will be received. LinkedList of students will exist.
        @postconditions - The appropriate student will be deleted and removed
        from the LinkedList.
        @return - void
        */
        void handleDropOut(std::string command, LinkedList<ItemType>& list);
        
        /*
        @preconditions - A string will be received containing the minimum
        GPA for which to qualify for honors. LinkedList of students will exist.
        @postconditions - The students with the GPA above the threshold will
        be printed.
        @return - void
        */
        void handleHonorsGPA(std::string command, LinkedList<ItemType>& list);
        
        /*
        @preconditions - The information for the new student will be received.
        The LinkedList of student records will exist.
        @postconditions - The new student will be added to the records, if the
        student ID doesn't already exist in the records.
        @return - void
        */
        void handleNewStudent(std::string command, LinkedList<ItemType>& list);
        
        /*
        @preconditions - The LinkedList of the students will be received.
        @postconditions - All students and their information will be printed.
        @return - void
        */
        void handlePrintAll(LinkedList<ItemType>& list);
        
        /*
        @preconditions - A string containing a student ID will be received,
        as well as the students LinkedList.
        @postconditions - The specified student's information will be printed,
        if he or she exists in the records.
        @return - void
        */
        void handlePrintStudent(std::string command, LinkedList<ItemType>& list);
        
};

#endif
