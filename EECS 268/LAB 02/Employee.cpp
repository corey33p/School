#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;


Employee::Employee(){}
Employee::Employee(string data){
    // data to be of the form "firstName lastName age"
    // firstName
    int _index = data.find_first_of(" ");
    string firstName = data.substr(0,_index);
    Employee::setfirstName(firstName);
    // lastName
    data = data.substr(_index+1,-1);
    _index = data.find_first_of(" ");
    string lastName = data.substr(0,_index);
    Employee::setlastName(lastName);
    // age
    string age = data.substr(_index+1,-1);
    Employee::setage(age);
}
Employee::~Employee(){}
//
string Employee::getID(){return Employee::employeeID;}
string Employee::getage(){return Employee::age;}
string Employee::getfirstName(){return Employee::firstName;}
string Employee::getlastName(){return Employee::lastName;}
//
void Employee::setID(string ID){Employee::employeeID = ID;}
void Employee::setage(string age){Employee::age = age;}
void Employee::setfirstName(string name){Employee::firstName = name;}
void Employee::setlastName(string name){Employee::lastName = name;}
void Employee::print(){
    cout<<"Employee "<<Employee::getfirstName()<<" "<<Employee::getlastName()<<" - Age: "<<Employee::getage()<<endl;
}

Manager::Manager(string data){
    // data to be of the form "firstName lastName age"
    // firstName
    int _index = data.find_first_of(" ");
    string firstName = data.substr(0,_index);
    Manager::setfirstName(firstName);
    // lastName
    data = data.substr(_index+1,-1);
    _index = data.find_first_of(" ");
    string lastName = data.substr(0,_index);
    Manager::setlastName(lastName);
    data = data.substr(_index+1,-1);
    // age
    _index = data.find_first_of(" ");
    string age = data.substr(0,_index);
    Manager::setage(age);
    // department
    string department = data.substr(_index+1,-1);
    Manager::setdepartment(department);
}
string Manager::getdepartment(){return Manager::department;}
void Manager::setdepartment(string department){Manager::department = department;}
void Manager::print(){
    cout<<"Manager "<<Manager::getfirstName()<<" "<<Manager::getlastName()<<" - Age: "<<Manager::getage()<<" - Department: "<<Manager::getdepartment()<<endl;
}
