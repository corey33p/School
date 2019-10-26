using namespace std;
#include <iostream>
// #include <stdexcept>
#include "City.h"
        
City::City(std::istream& inp, int rows, int cols, int sRow, int sCol){
    City::sewerFound = false;
    City::size[0] = rows;
    City::size[1] = cols;
    City::start[0] = sRow;
    City::start[1] = sCol;
    City::city = new int*[rows];
    for (int i=0; i<rows;i++){
        City::city[i] = new int[cols];
        City::city[i] = new int[cols];
    }
    int matrixIndex = 0;
    std::string next_input;
    std::string line;
    while (std::getline(inp, line)){
        for (int i = 0; i < (int)line.size(); i++){
            next_input = line[i];
            int row = matrixIndex / cols;
            int col = matrixIndex % cols;
            if (next_input == "#"){
                if (matrixIndex >= rows*cols) { throw std::range_error("Attempting to write to city array but array is already full.");}
                City::city[row][col] = 1;
                matrixIndex++;
            }
            else if (next_input == " "){
                if (matrixIndex >= rows*cols) { throw std::range_error("Attempting to write to city array but array is already full.");}
                City::city[row][col] = 0;
                matrixIndex++;
            }
            else if (next_input == "@"){
                if (matrixIndex >= rows*cols) { throw std::range_error("Attempting to write to city array but array is already full.");}
                City::city[row][col] = 2;
                matrixIndex++;
            }
        }
    }
    City::findSewers();
}

City::~City(){
    for (int row = 0; row < City::size[0]; row++){
        delete[] City::city[row];
    }
    delete[] City::city;
    for (int i = 0; i < City::numberOfSewers; i++){
        delete[] City::sewerLocations[i];
    }
    delete[] City::sewerLocations;
}

void City::begin(){
    // City::city = City::step(City::city,City::start[0],City::start[1]);
    City::step(City::city,City::start[0],City::start[1]);
}

void City::step(int** c, int curRow, int curCol){
    // cout<<"current position: "<<curRow<<", "<<curCol<<endl;
    if (c[curRow][curCol]==0){ c[curRow][curCol]=-1; }
    else if (c[curRow][curCol]==2){ c[curRow][curCol]=-2; }
    // City::printCity();
    // system("pause");
    int possibleSteps[4][2] = {{curRow-1,curCol},{curRow,curCol+1},{curRow+1,curCol},{curRow,curCol-1}};
    bool goodSteps[4]={true,true,true,true};
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            int coordinate = possibleSteps[i][j];
            if (coordinate < 0){
                goodSteps[i] = false;
            } else if (coordinate > City::size[j]-1){
                goodSteps[i] = false;
            } 
        }
        if (goodSteps[i]){
            int row = possibleSteps[i][0];
            int col = possibleSteps[i][1];
            int gameVal = c[row][col];
            if ((gameVal == -2) || (gameVal == -1) || (gameVal == 1)){
                goodSteps[i] = false;
            }
        }
    }
    bool foundSewer = false;
    for (int i = 0; i < 4; i++){
        if (goodSteps[i]) {
            int row = possibleSteps[i][0];
            int col = possibleSteps[i][1];
            if (c[row][col]==0){
                // City::city = City::step(c,row,col);
                City::step(c,row,col);
            } else if (c[row][col]==2){
                foundSewer = true;
            }
        }
    }
    if (foundSewer && !City::sewerFound){
        City::sewerFound = true;
        for (int i = 0; i < City::numberOfSewers; i++){
            int row = City::sewerLocations[i][0];
            int col = City::sewerLocations[i][1];
            // City::city = City::step(c,row,col);
            City::step(c,row,col);
        }
    }
    // return City::city;
}

void City::findSewers() {
    City::numberOfSewers=0;
    for (int row = 0; row < City::size[0]; row++){
        for (int col = 0; col < City::size[1]; col++){
            if (City::city[row][col] == 2){
                City::numberOfSewers++;
            }
        }
    }
    City::sewerLocations = new int*[City::numberOfSewers];
    for (int i=0; i<City::numberOfSewers;i++){
        City::sewerLocations[i] = new int[2];
    }
    int sewersPlaced = 0;
    for (int row = 0; row < City::size[0]; row++){
        for (int col = 0; col < City::size[1]; col++){
            if (City::city[row][col] == 2){
                City::sewerLocations[sewersPlaced][0]=row;
                City::sewerLocations[sewersPlaced][1]=col;
                sewersPlaced++;
            }
        }
    }
    // for (int i=0; i<City::numberOfSewers;i++){
        // cout<<"City::sewerLocation: "<<City::sewerLocations[i][0]<<", "<<City::sewerLocations[i][1]<<endl;
    // }
}

void City::printCity() {
    int rows = City::size[0];
    int cols = City::size[1];
    int val;
    std::string strVal;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++) {
            std::string entry;
            val = City::city[row][col];
            if (val == -2){ strVal = "@"; }
            else if (val == -1){ strVal = "B"; }
            else if (val == 0){ strVal = " "; }
            else if (val == 1){ strVal = "#"; }
            else if (val == 2){ strVal = "@";}
            entry = entry + strVal;
            cout<<entry<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
