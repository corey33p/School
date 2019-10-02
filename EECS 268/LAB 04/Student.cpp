/*
@author - Corey Anderson
@file - Student.cpp
@date - 10/1/2019
@brief - Object will contain student information.
*/

using namespace std;
#include <iostream>
#include <string>
#include "Student.h"
// #include "LinkedList.h"
using namespace std;

Student::Student(){}
Student::Student(int ID,string fn,string ln,string lvl,int hours,int points):
                        studentID(ID),firstName(fn),lastName(ln),level(lvl),
                        creditHoursCompleted(hours),gradePointsEarned(points){
    }
Student::~Student(){}
int Student::getstudentID(){return studentID;}
string Student::getfirstName(){return firstName;}
string Student::getlastName(){return lastName;}
string Student::getlevel(){return level;}
int Student::getcreditHoursCompleted(){return creditHoursCompleted;}
int Student::getgradePointsEarned(){return gradePointsEarned;}
double Student::getGPA(){return (double) Student::getgradePointsEarned() / (double) Student::getcreditHoursCompleted();}
