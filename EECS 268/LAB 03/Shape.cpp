#include "Shape.h"
#include <iostream>
using namespace std;

// circle
Circle::Circle(){}
Circle::Circle(double r){
    Circle::radius = r;
}
Circle::~Circle(){}
double Circle::area(){
    return Circle::pi * radius * radius;
}
std::string Circle::shapeName(){
    return Circle::Name;
}
void Circle::print(){
    cout<<"Circle area = "<<area()<<endl;
}

// rectangle
Rectangle::Rectangle(){}
Rectangle::Rectangle(double length, double width){
    Rectangle::recLength = length;
    Rectangle::recWidth  = width;
}
Rectangle::~Rectangle(){}
double Rectangle::area(){
    return Rectangle::recLength * Rectangle::recWidth;
}
std::string Rectangle::shapeName(){
    return Rectangle::Name;
}
void Rectangle::print(){
    cout<<"Rectangle area = "<<area()<<endl;
}

// triangle
Triangle::Triangle(){}
Triangle::Triangle(double base, double height){
    Triangle::triangleBase = base;
    Triangle::triangleHeight = height;
}
Triangle::~Triangle(){}
double Triangle::area(){
    return 1/2*Triangle::triangleBase*Triangle::triangleHeight;
}
std::string Triangle::shapeName(){
    return Triangle::Name;
}
void Triangle::print(){
    cout<<"Triangle area = "<<area()<<endl;
}
