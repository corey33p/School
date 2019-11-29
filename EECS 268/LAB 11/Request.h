/*
@author - Corey Anderson
@file - Request.h
@date - 11/29/2019
@brief - Request item to be managed by a priority queue. Stores first name,
last name, and priority number of customers whose power stations need repaired.
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

class Request{
    private:
        std::string firstName;
        std::string lastName;
        int priorityNumber;
    public:
        Request();
        Request(const Request& r);
        Request(std::string firstName,std::string lastName,int priorityNumber);
        ~Request();
        void print();
        std::string getfirstName() const;
        std::string getlastName() const;
        int getpriorityNumber() const;
};

#endif
