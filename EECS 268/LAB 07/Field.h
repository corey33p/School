/*
@author - Corey Anderson
@file - Field.h
@date - 10/12/2019
@brief - This object will store information defining the game field,
and also information and methods pertaining to the solution.
*/

#include <iostream>

#ifndef FIELD_H
#define FIELD_H


class Field {
    private:
        // to keep track of the +'s, -'s, S's and E's that define the field
        int** field;
        
        // to keep track of the sequence of the steps taken in the game
        int** steps;
        
        // integers relating to the number of rows and columns in the field
        int size[2];
        
        // keep track of whether a solution has been found
        bool solutionFound;
    public:
        // Data will be read in from a file stream to create the field matrix.
        Field(std::istream& inp, int rows, int cols);
        
        // Arrays to be deallocated
        ~Field();
        
        // Method to start the executive of the recursive step() function.
        // This is required because some of the function parameters of the step
        // function are private class variables, and so step() can't be
        // accessed directly by a client.
        void start();
        
        // Recursive backtracking function to find solutions to the game.
        int** step(int** f, int** s, bool original);
        
        // prints the steps taken in during the game. Used to display the
        // end result and was useful for debugging.
        void printSteps();
        
        // prints the field defined by the file that was read in
        void printField();
};

#endif
