using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include "Executive.h"
#include "Map.h"
#include "Employee.h"
#include "DictEntry.h"

Executive::Executive(){}
Executive::~Executive(){}
void Executive::run(int argc, char **argv) {
    vector<string> dictLines;
    // string dictKeys[];
    // string dictEntries[];
    bool got_file = false;
    std::string file1 = argv[1];
    while (!got_file){
        got_file = readFile(file1,dictLines);
    }
    //
    vector<string> employeeLines;
    got_file = false;
    std::string file2 = argv[2];
    while (!got_file){
        got_file = readFile(argv[2],employeeLines);
    }
    //
    Map<string, DictEntry> dictMap;
    Executive::parseDict(dictLines,dictMap);
    //
    Map<string, Employee> employeeMap;
    Executive::parseEmployees(employeeLines,employeeMap);
    //
    Map<string, Manager> managerMap;
    Executive::parseManagers(employeeLines,managerMap);
    //
    Executive::runMenu(dictMap, employeeMap,managerMap);
}

bool Executive::readFile(string fileName,vector<string> &lines){
    std::ifstream in(fileName.c_str());
    if(!in) {
        std::cerr << "Cannot open the File: "<<fileName<<std::endl;
        return false;
    }
    string line;
    while (std::getline(in, line)) {
        int spaces_in_data = line.find(" ");
        if (spaces_in_data!=(int) std::string::npos){
            lines.push_back(line);
        }
    }
    in.close();
    return true;
}

template <typename Domain, typename Range>
void Executive::parseDict(vector<string> data,Map<Domain, Range> &map){
    for (auto & line : data) {
        int space_index = line.find_first_of(" ");
        string domainElement = line.substr(0,space_index);
        map.add(domainElement,DictEntry(line));
    }
}

template <typename Domain1, typename Range1>
void Executive::parseManagers(vector<string> data,Map<Domain1, Range1> &map){
    for (auto & line : data) {
        int _index = line.find_first_of(" ");
        string employeeID = line.substr(0,_index);
        line = line.substr(_index+1,-1);
        _index = line.find_first_of(" ");
        //
        string employeeType = line.substr(0,_index);
        line = line.substr(_index+1,-1);
        if (employeeType == "Manager"){
            _index = line.find_last_of(" ");
            string department = line.substr(_index+1,-1);
            // line = line.substr(0,_index);
            Manager newManager(line);
            newManager.setdepartment(department);
            map.add(employeeID,newManager);
        }
    }
}

template <typename Domain1, typename Range1>
void Executive::parseEmployees(vector<string> data,Map<Domain1, Range1> &map){
    for (auto & line : data) {
        int _index = line.find_first_of(" ");
        string employeeID = line.substr(0,_index);
        line = line.substr(_index+1,-1);
        _index = line.find_first_of(" ");
        //
        string employeeType = line.substr(0,_index);
        line = line.substr(_index+1,-1);
        if (employeeType == "Employee"){
            map.add(employeeID,Employee(line));
        }
    }
}

template <typename Domain2, typename Range2, typename Domain3, typename Range3, typename Domain5, typename Range5>
void Executive::runMenu(Map<Domain2, Range2> dictMap, Map<Domain3, Range3> employeeMap, Map<Domain5, Range5> managerMap){
    // employeeMap.printMap();
    // managerMap.printMap();
    string choice = "a";
    string valid_choices[] = {"q","Q","d","D","e","E"};
    bool foundSomething;
    while ((choice != "q") && (choice != "Q")) {
        cout<<"-------------------------------------------\n";
        cout<<"Press D to look up a word in the dictionary\n";
        cout<<"Press E to look up an employee\n";
        cout<<"Press Q to terminate the application\n";
        cout<<"-----> ";
        cin>>choice;
        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
        if ((choice == "d") || ( choice == "D")){
            cout<<"What is the word you would like to look up? ---> ";
            string word;
            cin>>word;
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            foundSomething = dictMap.lookup(word);
            choice = "a";
        } else if ((choice == "e") || ( choice == "E")) {
            cout<<"Please enter an employee ID. ---> ";
            string employeeID;
            cin>>employeeID;
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            foundSomething = employeeMap.lookup(employeeID);
            if (!foundSomething){
                foundSomething = managerMap.lookup(employeeID);
            }
            choice = "a";
        } else if ((choice != "q") && ( choice != "Q")) {
            std::cerr<<"Not a valid choice.\n";
            choice = "a";
            foundSomething = true;
        } else if ((choice == "q") || ( choice == "Q")) {
            foundSomething = true;
        }
        if (!foundSomething) {cout<<"Found no results.\n";}
    }
}
