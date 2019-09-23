#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string data);
        virtual ~Employee();
        virtual void print();
        //
        string getID();
        string getage();
        string getfirstName();
        string getlastName();
        //
        void setID(string ID);
        void setage(string age);
        void setfirstName(string name);
        void setlastName(string name);
    private:
        string employeeID;
        string age;
        string firstName;
        string lastName;
};

#endif 

#ifndef MANAGER_H
#define MANAGER_H

class Manager : public Employee
{
    public:
        Manager(string data);
        void print();
        void setdepartment(string department);
        string getdepartment();
    private:
        string department;
};

#endif