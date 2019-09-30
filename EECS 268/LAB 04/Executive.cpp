using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
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
void Executive<Student>::run(std::istream& students, std::istream& commands){
    std::istreambuf_iterator<char> eos;
    std::string studentsFile;
    students >> studentsFile;
    std::string commandsFile; 
    commands >> commandsFile;
	LinkedList<Student> list;
	Executive<Student>::read(studentsFile, list); // on return, "list" will have the student list
    handlePrintAll(list);
	std::string command;
    cout<<"-----> ";
    string commandParameters;
	while (commands >> command){
        // make command lowercase, just in case
        std::transform(command.begin(), command.end(), command.begin(), 
            [](unsigned char c){ return std::tolower(c); });
        
        // parse command
        int space_index = command.find_first_of(" ");
        commandParameters = command.substr(space_index+1,-1);
        command = command.substr(0,space_index);
        
        // pass command
		if (command == "class"){
			handleClass(command, list);
		} else if (command == "dropout"){
			handleDropOut(command, list);
		} else if (command == "honors"){
			handleHonorsGPA(command, list);
        } else if (command == "newstudent"){
			handleNewStudent(command, list);
        } else if (command == "printall"){
			handlePrintAll(list);
        } else if (command == "printstudent"){
			handlePrintStudent(command, list);
        } else if (command == "quit"){
            break;
        }
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
void Executive<Student>::handleClass(std::string command, LinkedList<Student> list){
    std::string _class;
    vector<int> ids;
    //
    std::replace( command.begin(), command.end(), '\t', ' ');
    int space_index = command.find_first_of(" ");
    _class = command.substr(0,space_index);
    command = command.substr(space_index+1,-1);
    //
    int newID;
    string newID_in;
    while (command.length() > 0){
        space_index = command.find_first_of(" ");
        newID_in = command.substr(0,space_index);
        stringstream ss(newID_in);
        ss>>newID;
        ids.push_back(newID);
        command = command.substr(space_index+1,-1);
    }
}

template<class Student>
void Executive<Student>::handleDropOut(std::string command, LinkedList<Student>& list){
    bool found = false;
    Student student;
    for (int i = 0; i < list.getLength();i++){
        student = list.getEntry(i);
        // if (student.getstudentID() == 
    }
}

template<class Student>
void Executive<Student>::handleHonorsGPA(std::string command, LinkedList<Student> list){
    
}

template<class Student>
void Executive<Student>::handleNewStudent(std::string command, LinkedList<Student>& list){
    
}

template<class Student>
void Executive<Student>::handlePrintAll(LinkedList<Student> list){
    Student student;
    for (int i = 0; i < list.getLength();i++){
        student = list.getEntry(i);
        //
        cout<<student.getlastName()<<", ";
        cout<<student.getfirstName()<<":\n    ";
        cout<<"Student ID: "<<student.getstudentID()<<",\n    ";
        cout<<"Level: "<<student.getlevel()<<",\n    ";
        //
        int hours = student.getcreditHoursCompleted();
        int points= student.getgradePointsEarned();
        double gpa = (double) points / (double) hours;
        //
        cout<<"Credit Hours: "<<hours<<",\n    ";
        cout<<"Grade Points: "<<points<<",\n    ";
        cout<<"GPA: "<<gpa<<endl;
    }
}

template<class Student>
void Executive<Student>::handlePrintStudent(std::string command, LinkedList<Student> list){
    
}

template class Executive<Student>;
template class LinkedList<Student>;