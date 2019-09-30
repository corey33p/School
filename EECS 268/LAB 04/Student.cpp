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
    // cout<<"line: "<<ID<<endl;
    // cout<<"firstName: "<<fn<<endl;
    // cout<<"lastName: "<<ln<<endl;
    // cout<<"level: "<<lvl<<endl;
    // cout<<"hoursCompleted_in: "<<hours<<endl;
    // cout<<"pointsEarned_in: "<<points<<endl<<endl;
    }
Student::~Student(){}
int Student::getstudentID(){return studentID;}
string Student::getfirstName(){return firstName;}
string Student::getlastName(){return lastName;}
string Student::getlevel(){return level;}
int Student::getcreditHoursCompleted(){return creditHoursCompleted;}
int Student::getgradePointsEarned(){return gradePointsEarned;}

