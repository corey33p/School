/*
@author - Corey Anderson
@file - Executive.cpp
@date - 10/1/2019
@brief - Will process input files for student data, as well as commands to
handle the data.
*/

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Executive.h"
#include "Student.h"
#include "ListInterface.h"
#include "LinkedList.h"


template<class Student>
Executive<Student>::Executive(){}
template<class Student>
Executive<Student>::~Executive(){}

template<class Student>
void Executive<Student>::read(std::string studentsFile, LinkedList<Student>& list){
    vector<string> txtFileLines;
    bool got_file = false;
    while (!got_file){
        got_file = readFile(studentsFile,txtFileLines);
    }
    //
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
        // cout<<"line: "<<line<<endl;
        std::replace( line.begin(), line.end(), '\t', ' ');
        //
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
        stringstream ss1(hoursCompleted_in);
        ss1>>hoursCompleted;
        line = line.substr(space_index+1,-1);
        //
        space_index = line.find_first_of(" ");
        pointsEarned_in = line.substr(0,space_index);
        stringstream ss2(pointsEarned_in);
        ss2>>pointsEarned;
        line = line.substr(space_index+1,-1);
        // -----------------------
        // cout<<"line: "<<id<<endl;
        // cout<<"firstName: "<<firstName<<endl;
        // cout<<"lastName: "<<lastName<<endl;
        // cout<<"level: "<<level<<endl;
        // cout<<"hoursCompleted_in: "<<hoursCompleted_in<<endl;
        // cout<<"pointsEarned_in: "<<pointsEarned_in<<endl<<endl;
        Student student = Student(id,firstName,lastName,level,hoursCompleted,pointsEarned);
        try {
            list.insert(-1,student);
        } catch (PrecondViolatedExcep &except){
            cout<< except.what() << '\n';
        }
    }
}

template<class Student>
std::vector<std::string> Executive<Student>::readCommands(std::string commandsFile){
    std::vector<std::string> commands;
    bool got_file = false;
    while (!got_file){
        got_file = readFile(commandsFile,commands);
    }
    return commands;
}

template<class Student>
void Executive<Student>::run(char** argv){
    // get students
	LinkedList<Student> list;
	Executive<Student>::read(argv[1], list);
    
    // get commands
    vector<string> commands_in = readCommands(argv[2]);
    
    // do commands
    handlePrintAll(list);
	std::string command;
    string commandParameters;
    int command_index = 0;
	while (true){
        if (command_index <= (int) commands_in.size()){
            if (command_index == 0){ cout<<"-----> "; }
            command = commands_in[command_index];
            cout<<command<<endl;
            command_index++;
        }else{
            std::getline(std::cin, command);
        }
        
        // parse command
        int space_index = command.find_first_of(" ");
        commandParameters = command.substr(space_index+1,-1);
        command = command.substr(0,space_index);
        std::transform(command.begin(), command.end(), command.begin(),
            [](unsigned char c){ return std::tolower(c); });
        
        try{
            // pass command
    		if (command == "class"){
    			handleClass(commandParameters, list);
    		} else if (command == "dropout"){
    			handleDropOut(commandParameters, list);
    		} else if (command == "honors"){
    			handleHonorsGPA(commandParameters, list);
            } else if (command == "newstudent"){
    			handleNewStudent(commandParameters, list);
            } else if (command == "printall"){
    			handlePrintAll(list);
            } else if (command == "printstudent"){
    			handlePrintStudent(commandParameters, list);
            } else if (command == "quit"){
                break;
            }
        } catch(PrecondViolatedExcep &except) {}
    cout<<"-----> ";
	}
	return;
}

template<class Student>
bool Executive<Student>::readFile(std::string fileName,vector<std::string> &lines){
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
//-------------------------------------------------------//
//-------------------Handling Commands-------------------//
//-------------------------------------------------------//

template<class Student>
void Executive<Student>::handleClass(std::string command, LinkedList<Student>& list){
    std::string _class;
    // vector<int> ids;
    //
    std::replace( command.begin(), command.end(), '\t', ' ');
    //
    int space_index = command.find_first_of(" ");
    _class = command.substr(0,space_index);
    command = command.substr(space_index+1,-1);
    //
    std::stringstream ss(command);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> ids(begin, end);
    //
    int intID;
    cout<<"Class roster for "<<_class<<": "<<endl;
    bool found = false;
    bool subFound = false;
    for (auto & id : ids) {
        subFound = false;
        for (int i = 0; i < list.getLength();i++){
            Student student = list.getEntry(i);
            stringstream ss(id);
            ss>>intID;
            if (student.getstudentID() == intID){
                cout<<"    ";
                cout<<student.getlastName()<<", ";
                cout<<student.getfirstName()<<":\n        ";
                cout<<"Student ID: "<<student.getstudentID()<<",\n        ";
                cout<<"Level: "<<student.getlevel()<<",\n        ";
                //
                int hours = student.getcreditHoursCompleted();
                int points= student.getgradePointsEarned();
                double gpa = student.getGPA();
                //
                cout<<"Credit Hours: "<<hours<<",\n        ";
                cout<<"Grade Points: "<<points<<",\n        ";
                cout<<"GPA: "<<gpa<<endl;
                //
                found = true;
                subFound = true;
            }
        }
        if (!subFound){cout<<"    No record found for student ID "<<id<<"."<<endl;}
    }
    if (!found) {
        cout<<"Found no student in class "<<_class<<endl<<endl;
        throw PrecondViolatedExcep("Found no student in class.");
    }
    cout<<endl;
}

template<class Student>
void Executive<Student>::handleDropOut(std::string command, LinkedList<Student>& list){
    command.erase(std::remove(command.begin(), command.end(), ' '), command.end());
    int id;
    stringstream ss(command);
    ss>>id;
    bool found = false;
    //
    string fName;
    string lName;
    //
    Student student;
    for (int i = 0; i < list.getLength();i++){
        student = list.getEntry(i);
        if (student.getstudentID() == id){
            fName = student.getfirstName();
            lName = student.getlastName();
            list.remove(i);
            cout<<fName<<" "<<lName<<" dropped out succesfully."<<endl;
            found = true;
        }
    }
    if (!found){
        cout<<"Student ID "<<id<<" did not match any records."<<endl;
        throw PrecondViolatedExcep("Student ID did not match any records.");
    }
    cout<<endl;
}

template<class Student>
void Executive<Student>::handleHonorsGPA(std::string command, LinkedList<Student>& list){
    command.erase(std::remove(command.begin(), command.end(), ' '), command.end()); // remove spaces, just in cases
    double gpa;
    stringstream ss(command);
    ss>>gpa;
    bool found = false;
    //
    string fName;
    string lName;
    //
    Student student;
    for (int i = 0; i < list.getLength();i++){
        student = list.getEntry(i);
        if (student.getGPA() >= gpa){
            cout<<student.getlastName()<<", ";
            cout<<student.getfirstName()<<":\n    ";
            cout<<"Student ID: "<<student.getstudentID()<<",\n    ";
            cout<<"Level: "<<student.getlevel()<<",\n    ";
            //
            int hours = student.getcreditHoursCompleted();
            int points= student.getgradePointsEarned();
            double gpa = student.getGPA();
            //
            cout<<"Credit Hours: "<<hours<<",\n    ";
            cout<<"Grade Points: "<<points<<",\n    ";
            cout<<"GPA: "<<gpa<<endl;
            //
            found = true;
        }
    }
    if (!found){
        cout<<"No students found with a gpa above "<<gpa<<"! Bunch of slackers..."<<endl<<endl;
        throw PrecondViolatedExcep("No students with required GPA.");
    }
    else {cout<<endl;}
}

template<class Student>
void Executive<Student>::handleNewStudent(std::string command, LinkedList<Student>& list){
    // parsing
    int id;
    int space_index = command.find_first_of(" ");
    string newID_in = command.substr(0,space_index);
    stringstream ss(newID_in);
    ss>>id;
    command = command.substr(space_index+1,-1);
    //
    space_index = command.find_first_of(" ");
    string fn = command.substr(0,space_index);
    command = command.substr(space_index+1,-1);
    //
    space_index = command.find_first_of(" ");
    string ln = command.substr(0,space_index);
    command = command.substr(space_index+1,-1);
    command.erase(std::remove(command.begin(), command.end(), ' '), command.end()); // remove spaces, just in cases
    //
    string lvl = command;
    //
    bool found = false;
    //
    Student student;
    for (int i = 0; i < list.getLength();i++){
        student = list.getEntry(i);
        if (student.getstudentID() == id){
            found = true;
        }
    }
    if (found){
        cout<<"Student ID "<<id<<" already exists."<<endl;
        throw PrecondViolatedExcep("Student ID already exists.");
    }
    else {
        Student student = Student(id,fn,ln,lvl,0,0);
        list.insert(0,student);
        cout<<"Student Mike Smith added successfully."<<endl;
    }
    cout<<endl;
}

template<class Student>
void Executive<Student>::handlePrintAll(LinkedList<Student>& list){
    bool any_printed = false;
    for (int i = 0; i < list.getLength();i++){
        Student student = list.getEntry(i);
        //
        cout<<student.getlastName()<<", ";
        cout<<student.getfirstName()<<":\n    ";
        cout<<"Student ID: "<<student.getstudentID()<<",\n    ";
        cout<<"Level: "<<student.getlevel()<<",\n    ";
        //
        int hours = student.getcreditHoursCompleted();
        int points= student.getgradePointsEarned();
        double gpa = student.getGPA();
        //
        cout<<"Credit Hours: "<<hours<<",\n    ";
        cout<<"Grade Points: "<<points<<",\n    ";
        cout<<"GPA: "<<gpa<<endl;
        //
        any_printed = true;
    }
    if (!any_printed){
        cout<<"No students on the roster!"<<endl<<endl;
        throw PrecondViolatedExcep("No students on the roster!");
    }
    cout<<"End of list!"<<endl<<endl;
}

template<class Student>
void Executive<Student>::handlePrintStudent(std::string command, LinkedList<Student>& list){
    int id;
    stringstream ss(command);
    ss>>id;
    bool found = false;
    for (int i = 0; i < list.getLength();i++){
        Student student = list.getEntry(i);
        if (student.getstudentID() == id){
            cout<<student.getlastName()<<", ";
            cout<<student.getfirstName()<<":\n    ";
            cout<<"Student ID: "<<student.getstudentID()<<",\n    ";
            cout<<"Level: "<<student.getlevel()<<",\n    ";
            //
            int hours = student.getcreditHoursCompleted();
            int points= student.getgradePointsEarned();
            double gpa = student.getGPA();
            //
            cout<<"Credit Hours: "<<hours<<",\n    ";
            cout<<"Grade Points: "<<points<<",\n    ";
            cout<<"GPA: "<<gpa<<endl;
            //
            found = true;
        }
    }
    // if (!found) {cout<<"Found no student with ID "<<id<<"."<<endl<<endl;}
    if (!found) {
        cout<<"Found no student with ID "<<id<<"."<<endl<<endl;
        throw PrecondViolatedExcep("Invalid student ID. ");}
    else {cout<<endl;}
}

template class Executive<Student>;
template class LinkedList<Student>;
