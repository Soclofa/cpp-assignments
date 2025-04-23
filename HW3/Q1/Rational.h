//  Rational.hpp
//  Homework Assignment #1
//  Created by Avi Soclof on 2/20/22.
//674098915
//Code allows for users to input rational numbers, apply basic arithmetic operations, and compare


#ifndef Rational_hpp
#define Rational_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

//Initialzing class with fields numerator and denominator
class Rational{

private:
    int numerator;
    int denominator;
    
    Rational reduction() const;
    int commonDenominator(const Rational) const; 
    
public:
    Rational() ;
    Rational(int, int);
    Rational(const Rational&);
    
    void setNumerator (int) ;
    void setDenominator(int) ;
    
    int getNumerator() const;
    int getDenominator() const;
    
    void print() const;
    
    //operators
    
    Rational operator + (const Rational&) const;
    Rational operator - (const Rational&) const;
    Rational operator / (const Rational&) const;
    Rational operator * (const Rational&) const;
    
    //pre
    Rational& operator ++();
    //post
    Rational operator ++(int) ;

    //pre
    Rational& operator --() ;
    //post
    Rational operator -- (int) ;
    
    
    bool operator == (const Rational&) const;
    bool operator != (const Rational&) const;
    bool operator < (const Rational&) const;
    bool operator > (const Rational&) const;
    bool operator <= (const Rational&) const;
    bool operator >= (const Rational&) const;
    
};

#endif /* Rational_hpp */
