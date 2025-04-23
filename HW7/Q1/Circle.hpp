//
//  Circle.hpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#ifndef Circle_hpp
#define Circle_hpp

#include "Shape.hpp"
#include <stdio.h>

class Circle : public Shape {
    
protected:
    float radius;
    
public:
    //constructor
    Circle(int);
    
    //copy constructor
    Circle(Circle&);
    
    //returns true if circle is canonical
    bool isSpecial() override;
    
    //printSpecial
    void printSpecial()  override;
    
    //calculates area
    float area() override;
};

#endif /* Circle_hpp */
