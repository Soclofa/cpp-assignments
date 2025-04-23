//
//  Shape.hpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include "Point.hpp"
#include <cmath> 


//this is an abstract class
class Shape {

    
protected:
    //Amount of points in the shape
    int numOfPoints;
    //An array of points in the shape
    Point* points;
    
public:
    
    //empty constructor
    Shape();
    //constuctor
    Shape(int);
    //copy constructor
    Shape(Shape&);
    //move constructor
    Shape(Shape&&);
    
    //virtual destructor
    virtual ~Shape();
    
    //area, isSpecial, and print special are all purely virtual
    virtual float area() = 0;
    virtual bool isSpecial() = 0;
    virtual void printSpecial() = 0;
    
    //ostream operator
    friend ostream& operator << (ostream&, Shape&);
    
    //returns if all sides of a shape are equal
    bool equalDistances();
    
};

#endif /* Shape_hpp */
