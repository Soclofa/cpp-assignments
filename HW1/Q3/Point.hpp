//
//  Point.hpp
//  Question3
//
//  Created by Avi Soclof on 2/21/22.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point
{
private:
    int x;
    int y;
public:
    void setX(int myX);
    void setY(int myY);
    int getX();
    int getY();
};


#endif /* Point_hpp */
