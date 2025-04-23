//
//  Clock.hpp
//  Clock
//
//  Created by Avi Soclof on 3/23/22.
//

#ifndef Clock_h
#define Clock_h
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include "Clock.hpp"
using namespace std; 

class Account;

class Clock {
    
private:
    int hour;
    int minute;
    int second;
    
    
public:
    //constructors
    Clock();
    Clock(int hr = 0, int min = 0, int sec = 0);
    
    //copy
    Clock(Clock&);
    Clock& operator= (Clock&);
    
    //move
    Clock(Clock&&);
    Clock& operator= (Clock&&);
    
    //setters
    void setHr (int);
    void setMin (int);
    void setSec (int);
    
    //getter
    int getHr() const;
    int getMin() const;
    int getSec() const;
    
    //operators
    Clock& operator += (int);
    
    //stream operators
    friend ostream& operator<< (ostream&, const Clock&);
    friend istream& operator>> (istream&,  Clock&);
    
    //classes
    friend class Account;
};



#endif /* Clock_hpp */
