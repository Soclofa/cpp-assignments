//
//  Circle.hpp
//  Question3
//
//  Created by Avi Soclof on 2/21/22.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "Point.hpp"
#define PI 3.14
class Circle
{
private:
    Point center;
    int radius;
public:
    void setCenter(int x, int y);
    void setRadius(int myRadius);
    Point getCenter();
    int getRadius();
    float area();
    float perimeter();
    int onInOut(Point p);
};


#endif /* Circle_hpp */
