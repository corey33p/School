/*
@author - Cory Anderson
@file - Executive.cpp
@date - 9/23/2019
@brief - This will serve as a parent object, which will import data from
a file and create the ShapeContainer data structure, which will handle all the
individual shapes.
*/

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Executive.h"
#include "ShapeContainer.h"
#include "Shape.h"

Executive::Executive(){}
Executive::~Executive(){}
void Executive::Executive::run(int argc, char **argv) {
    vector<string> txtFileLines;
    bool got_file = false;
    std::string file1 = argv[1];
    while (!got_file){
        got_file = readFile(file1,txtFileLines);
    }
    //
    parseData(txtFileLines);
}

bool Executive::Executive::readFile(std::string fileName,vector<std::string> &lines){
    std::ifstream in(fileName.c_str());
    if(!in) {
        std::cerr << "Cannot open the File: "<<fileName<<std::endl;
        return false;
    }
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    in.close();
    return true;
}

void Executive::parseData(vector<string> txtFileLines){
    std::string operationType;
    std::string arrayIndex_in;
    int arrayIndex;
    std::string shapeType;
    std::string parameter_1_in;
    std::string parameter_2_in;
    double parameter_1;
    double parameter_2;
    //
    string numberOfLines_in = txtFileLines[0];
    stringstream ss4(numberOfLines_in);
    int numberOfLines;
    ss4>> numberOfLines;
    //
    ShapeContainer Container = ShapeContainer(numberOfLines);
    // cout<<"txtFileLines.size(): "<<txtFileLines.size()<<endl;
    for (auto & line : txtFileLines) {
        int spaces_in_data = line.find(" ");
        if (spaces_in_data!=(int) std::string::npos){
            operationType="";
            arrayIndex_in="";
            arrayIndex=-1;
            shapeType="";
            parameter_1_in="";
            parameter_2_in="";
            parameter_1=-1;
            parameter_2=-1;
            //
            int space_index = line.find_first_of(" ");
            operationType = line.substr(0,space_index);
            //
            line = line.substr(space_index+1,-1);
            space_index = line.find_first_of(" ");
            arrayIndex_in = line.substr(0,space_index);
            stringstream ss3(arrayIndex_in);
            ss3>>arrayIndex;
            if (operationType == "ADD"){
                line = line.substr(space_index+1,-1);
                // cout<<"line: "<<line<<endl;
                space_index = line.find_first_of(" ");
                shapeType = line.substr(0,space_index);
                line = line.substr(space_index+1,-1);
                if (shapeType=="CIR"){
                    parameter_1_in = line.substr(0,-1);
                    stringstream ss0(parameter_1_in);
                    ss0>>parameter_1;
                } else {
                    space_index = line.find_first_of(" ");
                    parameter_1_in = line.substr(0,space_index);
                    stringstream ss1(parameter_1_in);
                    ss1>>parameter_1;
                    //
                    parameter_2_in = line.substr(space_index+1,-1);
                    stringstream ss2(parameter_2_in);
                    ss2>>parameter_2;
                }
            }
            //
            // cout<<"operation: "<<operationType;
            // cout<<" "<<arrayIndex;
            // cout<<" "<<shapeType;
            // cout<<" "<<parameter_1;
            // cout<<" "<<parameter_2<<endl;
            doCommand(Container,operationType,arrayIndex,shapeType,parameter_1,parameter_2);
        }
    }
}

void Executive::doCommand(ShapeContainer &container,
                          string command,
                          int index,
                          string shapeType,
                          double param1,
                          double param2){
    //
    try {
        // cout<<"command: "<<command<<endl;
        // cout<<"index: "<<index<<endl;
        if (command == "ADD"){
            if (shapeType == "CIR"){
                Circle* newShape = new Circle(param1);
                container.add(newShape,index);
            } else if (shapeType == "TRI"){
                Triangle* newShape = new Triangle(param1,param2);
                container.add(newShape,index);
            } else if (shapeType == "REC"){
                Rectangle* newShape = new Rectangle(param1,param2);
                container.add(newShape,index);
            }
        } else if (command == "DELETE"){
            container.remove(index);
        } else if (command == "PRINT"){
            cout<<"Shape at index "<<index<<": ";
            std::string shape;
            shape = container.shapeName(index);
            double shapeArea;
            shapeArea = container.area(index);
            cout<<shape<<" area: = "<<shapeArea<<endl;
        }
    } catch (std::range_error ia){
        cout<< ia.what() << '\n';
    } catch (std::exception ia){
        // cout<< ia.what() << '\n';
    }
}
