//
//  Point.hpp
//  Homework #2
//
//  Created by Avi Soclof on 2/24/22.
//

#ifndef Point_h
#define Point_h

#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std; 

class point {
    
private:
    int x;
    int y;
    
public:
    //empty constructor
    point();
    //regular constructor
    point(int, int);
    
    
    point (const point&);
    
    void setX(int);
    void setY(int);
    
    int getX();
    int getY();
    
    float distance(point&);
    
   
    
    
};


#endif /* Point_hpp */
