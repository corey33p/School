using namespace std{}
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "ShapeContainer.h"


Executive::Executive(){}
virtual Executive::~Executive(){}
void Executive::parseData(vector<string> txtFileLines){
    std::string id_in;
    int id;
    std::string firstName;
    std::string lastName;
    std::string level;
    std::string hoursCompleted_in;
    int hoursCompleted;
    std::string pointsEarned_in;
    int pointsEarned;
    //
    for (auto & line : txtFileLines) {
        int space_index = line.find_first_of(" ");
        id_in = line.substr(0,space_index);
        stringstream ss(id_in);
        ss>>id;
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        firstName = line.substr(0,space_index);
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        lastName = line.substr(0,space_index);
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        level = line.substr(0,space_index);
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        hoursCompleted_in = line.substr(0,space_index);
        stringstream ss1(id_in);
        ss1>>hoursCompleted;
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        pointsEarned_in = line.substr(0,space_index);
        stringstream ss1(id_in);
        ss1>>pointsEarned;
        line = line.substr(space_index+1,-1);
        // -----------------------

        cout<<"line: "<<id;
        cout<<" "<<firstName;
        cout<<" "<<lastName;
        cout<<" "<<level;
        cout<<" "<<hoursCompleted_in;
        cout<<" "<<pointsEarned_in<<endl;
        }
    }
}
void Executive::run(int argc, char** argv){
    vector<string> txtFileLines;
    bool got_file = false;
    std::string file1 = argv[1];
    while (!got_file){
        got_file = readFile(file1,txtFileLines);
    }
    //
    parseData(txtFileLines);
}
bool Executive::readFile(string fileName,vector<string> &lines){}
void Executive::doCommand(ShapeContainer &container, string command, int index, string shapeType, double param1, double param2){}
