//
//  Point.hpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std; 

class Circle;
class Triangle; 
class Rectangle;


class Point
{
private:
    int x;
    int y;
    
public:
    
    //empty constructor
    Point();
    
    //constructor
    Point (int, int);
    
    //setters
    void setX(const int myX);
    void setY(const int myY);
    
    //getters
    int getX() const; 
    int getY() const;
    
    //distanced between two points
    float distance(Point&);
    
    //istream operator 
    friend istream& operator >> (istream&, Point&);
    
    //allows for derived classes of Shape to access private members of Point
    //will allow for quicker calculation of length and area as well as access points directly
    friend class Triangle;
    friend class Circle;
    friend class Rectangle;
    

   
};



#endif /* Point_hpp */
