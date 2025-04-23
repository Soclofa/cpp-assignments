//
//  Rational.hpp
//  Homework Assignment #1
//
//  Created by Avi Soclof on 2/20/22.
//

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
    
    Rational reduction();
    
public:
    
    void setNumerator (int);
    void setDenominator(int);
    
    int getNumerator();
    int getDenominator();
    
    void print();
    
    Rational add(Rational);
   
    bool equal(Rational);
    
};



#endif /* Rational_hpp */
