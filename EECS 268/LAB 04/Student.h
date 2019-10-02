/*
@author - Corey Anderson
@file - Student.h
@date - 10/1/2019
@brief - Object will contain student information.
*/

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
        
        /*
        @preconditions - Student ID will exist.
        @postconditions -
        @return - Student ID will be returned.
        */
        int getstudentID();
        
        /*
        @preconditions - Student's first name will exist.
        @postconditions -
        @return - Student's first name will be returned.
        */
        string getfirstName();
        
        /*
        @preconditions - Student's last name will exist.
        @postconditions -
        @return - Student's last name will be returned.
        */
        string getlastName();
        
        /*
        @preconditions - Student's grade level will exist.
        @postconditions -
        @return - Student's grade level will be returned.
        */
        string getlevel();
        
        /*
        @preconditions - Student's credit hour count will exist.
        @postconditions -
        @return - Student's credit hour count will be returned.
        */
        int getcreditHoursCompleted();
        
        /*
        @preconditions - Student's grade point count will exist.
        @postconditions -
        @return - Student's grade point count will be returned.
        */
        int getgradePointsEarned();
        
        /*
        @preconditions - Student's credit hour count and grade point count
        will exist.
        @postconditions - Student's GPA will be computed.
        @return - Student's GPA will be returned. 
        */
        double getGPA();
};

#endif
