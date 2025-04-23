//
//  Rectangle.hpp
//  Shapes
//
//  Created by Avi Soclof on 4/14/22.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "Shape.hpp"




class Rectangle: public Shape{
    
public:
    //constructor
    Rectangle();
    
    //overrided virtual functions
    bool isSpecial() override;
    void printSpecial() override;
    float area() override;
    
};

#endif /* Rectangle_hpp */
