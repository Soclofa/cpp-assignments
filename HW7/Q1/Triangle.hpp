//
//  Triangle.hpp
//  Shapes
//
//  Created by Avi Soclof on 4/14/22.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Shape.hpp"

class Triangle : public Shape {
    
public:
    //constuctor
    Triangle();
    
    //override virtual methods
    bool isSpecial() override;
    void printSpecial() override;
    float area() override;
 
};

#endif /* Triangle_hpp */
