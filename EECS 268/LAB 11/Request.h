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
        Request(const Request&);
        Request(std::string firstName,std::string lastName,int priorityNumber);
        ~Request();
        void print();
        std::string getfirstName() const;
        std::string getlastName() const;
        int getpriorityNumber() const;
};

#endif
