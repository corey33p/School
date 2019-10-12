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

void Field::start(){ Field::steps = Field::step(Field::field, Field::steps, true); }

int** Field::step(int** f, int** s, bool original){
    int rows = Field::size[0];
    int cols = Field::size[1];
    int mSize = rows * cols;
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
    for (int i = 0;i<8;i++){
        int nRow = neighbors[i][0];
        int nCol = neighbors[i][1];
        bool validNeighbor = false;
        if ((nRow >= 0) && (nRow < rows)){
            if ((nCol >= 0) && (nCol < cols)){
                validNeighbor = true;
            }
        }
        if (validNeighbor){
            int neighborVal = s[nRow][nCol];
            if (neighborVal==0){
                if (f[nRow][nCol]==3){
                    if (maxStep == mSize-1){
                        s[nRow][nCol]=maxStep + 1;
                        solution = s;
                        Field::printSteps();
                        Field::solutionFound=true;
                    }
                } else if (f[nRow][nCol]==1){
                    if ((previousFieldVal==0)||(previousFieldVal==2)){
                        s[nRow][nCol]=maxStep + 1;
                        solution = Field::step(f,s,false);
                        s[nRow][nCol]=0;
                    }
                } else if (f[nRow][nCol]==0){
                    if ((previousFieldVal==1)||(previousFieldVal==2)){
                        s[nRow][nCol]=maxStep + 1;
                        solution = Field::step(f,s,false);
                        s[nRow][nCol]=0;
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
        cout<<"\nFound no solution."<<endl;
    }
    return solution;
}

void Field::printSteps() {
    int rows = Field::size[0];
    int cols = Field::size[1];
    cout<<endl;
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
