#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
#include <iostream>
#include <string>

class Student{
    private:
        int studentID;
        string firstName;
        string lastName;
        string level;
        int creditHoursCompleted;
        int gradePointsEarned;
    public:
        Student();
        Student(int ID,string fn,string ln,string lvl,int hours,int points);
        virtual ~Student();
        int getstudentID();
        string getfirstName();
        string getlastName();
        string getlevel();
        int getcreditHoursCompleted();
        int getgradePointsEarned();
};

#endif