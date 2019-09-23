/*
@author - Corey Anderson
@file - shape.h
@date - 9/23/2019
@brief - The Shape class will be an interface class, and there will be the 3
subclasses of Shape: Circle, Rectangle, and Triangle.

For notes on subclass shapes, see parent class Shape
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape
{
    public:
        /*
        @preconditions - The size parameters of the shape will be known.
        @postconditions - The area of the shape will be computed.
        @return - (double) The area of the shape will be returned.
        */
        virtual double area() = 0;

        /*
        @preconditions - None;
        @postconditions - the name of the shape will be set at constructor time
        @return - (std::string) the name of the shape
        */
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

        /*
        @preconditions - the radius will be received when the object is created
        @postconditions - the private variables radius, pi, and Name will be set
        @return - constructors don't return anything
        */
        Circle(double radius);
        virtual ~Circle();
        double area();
        std::string shapeName();
    private:
        double pi = 3.14159265358979323846;
        double radius;
        std::string Name = "Circle";

        /*
        @preconditions - the size parameters of the shape will be set
        @postconditions - the area of the shape will be computed and printed
        to the console
        @return - void
        */
        void print();
};
#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle : public Shape
{
    public:
        Rectangle();

        /*
        @preconditions - length and width will be received when the object is
        created
        @postconditions - private variables recLength, recWidth, Name will be set
        @return - constructors don't return anything
        */
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

        /*
        @preconditions - base and height will be received when the object is
        created
        @postconditions - private variables triangleBase, triangleHeight, Name
        will be set
        @return - constructors don't return anything
        */
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
