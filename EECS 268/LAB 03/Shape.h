#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape
{
    public:
        virtual double area() = 0;
        virtual std::string shapeName() = 0;
        virtual ~Shape() {}
    private:
        std::string Name;
};
#endif

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle : public Shape 
{
    public:
        Circle();
        Circle(double radius);
        virtual ~Circle();
        double area();
        std::string shapeName();
    private:
        double pi = 3.14159265358979323846;
        double radius;
        std::string Name = "Circle";
        void print();
};
#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Shape
{
    public:
        Rectangle();
        Rectangle(double length, double width);
        virtual ~Rectangle();
        double area();
        std::string shapeName();
    private:
        double recLength;
        double recWidth;
        std::string Name = "Rectangle";
        void print();
};
#endif

#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle : public Shape
{
    public:
        Triangle();
        Triangle(double base, double height);
        virtual ~Triangle();
        double area();
        std::string shapeName();
    private:
        double triangleBase;
        double triangleHeight;
        std::string Name = "Triangle";
        void print();
};
#endif