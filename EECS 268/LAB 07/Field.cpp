/*
@author - Corey Anderson
@file - Field.cpp
@date - 10/12/2019
@brief - This object will store information defining the game field,
and also information and methods pertaining to the solution.
*/

#include "Field.h"
#include <string>
#include <iostream>
using namespace std;

Field::Field(std::istream& inp, int rows,int cols){
    Field::solutionFound = false;
    Field::size[0] = rows;
    Field::size[1] = cols;
    Field::field = new int*[rows];
    Field::steps = new int*[rows];
    for (int i=0; i<rows;i++){
        Field::field[i] = new int[cols];
        Field::steps[i] = new int[cols];
    }
    std::string next_input;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            inp>>next_input;
            if (next_input == "+"){
                Field::field[row][col] = 1;
                Field::steps[row][col] = 0;
            }
            else if (next_input == "-"){
                Field::field[row][col] = 0;
                Field::steps[row][col] = 0;
            }
            else if ((next_input == "s") || (next_input == "S")){
                Field::field[row][col] = 2;
                Field::steps[row][col] = 1;
            }
            else if ((next_input == "e") || (next_input == "E")){
                Field::field[row][col] = 3;
                Field::steps[row][col] = 0;
            }
        }
    }
}

Field::~Field(){
    for (int row = 0; row < Field::size[0]; row++){
        delete[] Field::field[row];
        delete[] Field::steps[row];
    }
    delete[] Field::field;
    delete[] Field::steps;
}

void Field::start(){ Field::steps = Field::step(Field::field, Field::steps, true); }

int** Field::step(int** f, int** s, bool original){
    int rows = Field::size[0];
    int cols = Field::size[1];
    int mSize = rows * cols;
    
    // find the last step taken in the game, as well as its location
    int maxStep = 0;
    int lastStep[2];
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            if (s[row][col] > maxStep){
                maxStep = s[row][col];
                lastStep[0] = row;
                lastStep[1] = col;
            }
        }
    }
    
    // collect the neighboring game locations, which will be used as
    // candidates for the next move
    int neighbors[8][2];
    int i = 0;
    int previousFieldVal;
    int** solution;
    for (int row = lastStep[0]+1; row > lastStep[0]-2; row--){
        for (int col = lastStep[1]-1;col < lastStep[1]+2;col++){
            if ((row != lastStep[0]) || (col != lastStep[1])){
                neighbors[i][0] = row;
                neighbors[i][1] = col;
                i++;
            } else {
                previousFieldVal = f[row][col];
            }
        }
    }
    
    // iterate through all possible move locations
    for (int i = 0;i<8;i++){
        int nRow = neighbors[i][0];
        int nCol = neighbors[i][1];
        
        // determine whether candidate move is a legal move based
        // on the size of the board
        bool validNeighbor = false;
        if ((nRow >= 0) && (nRow < rows)){
            if ((nCol >= 0) && (nCol < cols)){
                validNeighbor = true;
            }
        }
        if (validNeighbor){ // if game location is valid
            int neighborVal = s[nRow][nCol]; // value 0 if not already visited, > 0 otherwise
            if (neighborVal==0){ // if the location hasn't been visited
                if (f[nRow][nCol]==3){ // if the location is the game's end position
                    if (maxStep == mSize-1){ // if the last step was the second to last step
                        s[nRow][nCol]=maxStep + 1; // assign the final step
                        solution = s;
                        cout<<"Solution: "<<endl;
                        Field::printSteps(); // print solution
                        Field::solutionFound=true; // game won
                    }
                } else if (f[nRow][nCol]==1){ // if the candidate location was a '+'
                    if ((previousFieldVal==0)||(previousFieldVal==2)){ // if the last location was a '-' or a 'S'
                        s[nRow][nCol]=maxStep + 1; // tentatively place the next step
                        solution = Field::step(f,s,false); // recursive call to try to solve the board based on the guess
                        s[nRow][nCol]=0; // reset the step value if it did not lead to a solution
                    }
                } else if (f[nRow][nCol]==0){ // if the candidate location was a '-'
                    if ((previousFieldVal==1)||(previousFieldVal==2)){// if the last location was a "+" or a 'S'
                        s[nRow][nCol]=maxStep + 1; // tentatively place the next step
                        solution = Field::step(f,s,false); // recursive call to try to solve the board based on the guess
                        s[nRow][nCol]=0; // reset the step value if it did not lead to a solution
                    }
                }
            }
        }
        solution = s;
        if (Field::solutionFound){
            return solution;
        }
    }
    if (!Field::solutionFound && original){
        cout<<"Found no solution."<<endl;
    }
    return solution;
}

void Field::printSteps() {
    int rows = Field::size[0];
    int cols = Field::size[1];
    std::string val;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            std::string entry;
            val = std::to_string(Field::steps[row][col]);
            for (int i = 0; i< (int)(4-val.length());i++){
                entry = entry + " ";
            }
            entry = entry + val;
            cout<<entry<<" ";
        }
        cout<<endl;
    }
}

void Field::printField() {
    int rows = Field::size[0];
    int cols = Field::size[1];
    int val;
    std::string strVal;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            std::string entry;
            val = Field::field[row][col];
            if (val == 1){ strVal = "+"; }
            else if (val == 0){ strVal = "-"; }
            else if (val == 2){ strVal = "S";}
            else if (val == 3){ strVal = "E";}
            for (int i = 0; i< (int)(4-strVal.length());i++){ entry = entry + " "; }
            entry = entry + strVal;
            cout<<entry<<" ";
        }
        cout<<endl;
    }
}
