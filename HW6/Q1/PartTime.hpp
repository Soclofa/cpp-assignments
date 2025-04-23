//
//  PartTime.hpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#ifndef PartTime_hpp
#define PartTime_hpp

#include <stdio.h>
#include "Employee.hpp"

class PartTime : public Employee {
    
    float hoursOfWork;
    float payPerHour;
    
public:
    
    PartTime();
    PartTime(string, int, int, float, float);
    PartTime(PartTime&);
    
    float getHoursOfWork() const;
    float getPayPerHour() const;
    
    void setHoursOfWork(float);
    void setPayPerHour(float);
    
    void salary();
     
    void print() const;
    friend istream& operator >> (istream&, PartTime&);
    friend ostream& operator << (ostream&, PartTime&);
    
};

#endif /* PartTime_hpp */
