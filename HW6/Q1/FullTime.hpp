//
//  FullTime.hpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#ifndef FullTime_hpp
#define FullTime_hpp

#include <stdio.h>
#include "Employee.hpp"

class FullTime : public Employee
{
    float salaryPerYear;
    
    
public:
    FullTime();
    FullTime(string, int, int ,float);
    FullTime(FullTime&);

    float getSalaryPerYear() const;
    void setSalaryPerYear(float);
    
    void salary();
    void print() const;
    
    friend istream& operator >> (istream&, FullTime&);
    friend ostream& operator << (ostream&, FullTime&);
    
};

#endif /* FullTime_hpp */
