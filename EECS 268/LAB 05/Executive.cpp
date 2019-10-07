using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Executive.h"
#include "Stack.h"
#include "Queue.h"
#include "Processor.h"
#include "Subprocess.h"

Executive::Executive(){}

Executive::~Executive(){}

void Executive::run(char** argv){
    vector<string> txtFileLines;
    bool got_file = false;
    std::string file1 = argv[1];
    got_file = readFile(file1,txtFileLines);
    if (!got_file){return;}
    //
    
    Processor processor;
    std::string command;
    std::string processName;
    for (auto & line : txtFileLines) {
        command = popWord(line);
        cout<<"COMMAND: "<<command<<endl;
        if (command == "START"){
            processName = popWord(line);
            std::vector<std::string> subprocesses;
            std::vector<bool> canHandle;
            // cout<<"line: "<<line<<endl;
            // cout<<"processName: "<<processName<<endl;
            // cout<<"canHandle: "<<canHandle<<endl;
            parseLine(line,subprocesses,canHandle);
            // cout<<"check"<<endl;
            processor.startProcess(processName,subprocesses,canHandle);
        } else if (command == "CPU"){
            processor.process();
        } else if (command == "THROW"){
            processor.throwException();
        } else if (command == "STATUS"){
            processor.printStatus();
        }
    }
}

std::string Executive::popWord(std::string& line){
    int space_index = line.find_first_of(" ");
    std::string theWord = line.substr(0,space_index);
    line = line.substr(space_index+1,-1);
    
    // get rid of spaces / newlines / etc
    theWord.erase(remove(theWord.begin(), theWord.end(), ' '), theWord.end());
    theWord.erase(remove(theWord.begin(), theWord.end(), '\n'), theWord.end());
    theWord.erase(remove(theWord.begin(), theWord.end(), '\r'), theWord.end());
    theWord.erase(remove(theWord.begin(), theWord.end(), '\t'), theWord.end());
    theWord.erase(remove(theWord.begin(), theWord.end(), '\f'), theWord.end());
    theWord.erase(remove(theWord.begin(), theWord.end(), '\v'), theWord.end());
    return theWord;
}

bool Executive::readFile(std::string fileName,vector<std::string> &lines){
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

void Executive::parseLine(std::string fileLine, std::vector<std::string>& subprocesses, std::vector<bool>& canHandle){
    subprocesses.push_back("main");
    canHandle.push_back(false);
    //
    std::string newSub;
    std::string newCanHandle;
    std::string next = Executive::popWord(fileLine);
    while (next != "0"){
        subprocesses.push_back(next);
        newCanHandle = popWord(fileLine);
        if (fileLine == "n"){ canHandle.push_back(false);}
        else { canHandle.push_back(true);}
        next = Executive::popWord(fileLine);
    }
}

template class Stack<Subprocess>;
// template class Processor<Stack<Subprocess>>;
