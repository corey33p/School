#include "Request.h"
#include <iostream>

Request::Request(){}

Request::Request(const Request&){}

Request::Request(std::string fName,std::string lName,int pNum){
    firstName = fName;
    lastName = lName;
    priorityNumber = pNum;
}

Request::~Request(){}

void Request::print(){
    cout<<"request "<<firstName<<" "<<lastName<<" "<<priorityNumber<<endl;
}

std::string Request::getfirstName() const{return firstName;}
std::string Request::getlastName() const{return lastName;}
int Request::getpriorityNumber() const{return priorityNumber;}
