//
//  Triangle.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/14/22.
//

#include "Triangle.hpp"
#include "Shape.hpp"

//calls shape constuctor, which dynamically allocates an array of three points and accepts user input to determine the points
Triangle::Triangle(): Shape(3){}


//The Triangle is considered special if all sides are the same (i.e it is a square).
//isSpecial calss the equalDistance function in the parent class and returns true if all the sides are the same
bool Triangle::isSpecial(){
    return Shape::equalDistances();
}

//if isSpecial is true, then printSpecial returns a special message with the distance of the length of one side
void Triangle::printSpecial(){
    if( isSpecial()){
        cout << "An equilateral triangle with a side length " << points[0].distance(points[1]) << endl;
    }
}

//uses heron's function to calculate area
float Triangle::area(){
    
    //a = side 1, b = side 2, c = side 3
    float a = points[0].distance(points[1]);
    float b = points[1].distance(points[2]);
    float c = points[2].distance(points[0]);
    
    float s = (a + b + c) / 2;
    
    return sqrt(s*(s-a)*(s-b)*(s-c));
}


