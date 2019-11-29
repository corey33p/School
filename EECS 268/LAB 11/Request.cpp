/*
@author - Corey Anderson
@file - Request.cpp
@date - 11/29/2019
@brief - Request item to be managed by a priority queue. Stores first name,
last name, and priority number of customers whose power stations need repaired.
*/

#include "Request.h"
#include <iostream>

Request::Request(){}

Request::Request(const Request& r){
    firstName = r.firstName;
    lastName = r.lastName;
    priorityNumber = r.priorityNumber;
}

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
