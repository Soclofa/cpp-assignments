//
//  Rational.cpp
//  Homework Assignment #1
//
//  Created by Avi Soclof on 2/20/22.
//


#include "Rational.h"

//setter for Numerator
void Rational::setNumerator(int _numerator){
    
    numerator = _numerator;

}

//setter for Denominator
void Rational::setDenominator(int _denominator){
    //checks for invalid denominator of 0 and changes it to 1
    if (_denominator != 0){
        denominator = _denominator;
    }
    else {
        denominator = 1;
    }
    
    //if both numerator and denominator are negative, the fraction is positive
    //if the denominator is negative, we make it positive and make the numerator negative
    if ((numerator < 0 && denominator < 0 )|| (numerator > 0 && denominator < 0)){
        numerator*=-1;
        denominator*=-1;
    }

}

//getter for numerator
int Rational::getNumerator(){
    return numerator;
}

//getter for denominator
int Rational::getDenominator(){
    return denominator;
}

//reduces the fraction
Rational Rational::reduction(){
  
    Rational reduced;

    
    int x = numerator;
    int y = denominator;
    
    int gcf = 1;
    
    //finds the greatest common factor and divdides accordingly 
    for (int i = 2; i <= ((x < 0) ? x*-1 : x); i++){
        if (x%i == 0 && y%i == 0){
            gcf = i;
        }
    }


    if (gcf != 1){
    x/=gcf;
    y/=gcf;
    
    
    if (y != 0){
    while (x%y == 0 && x!=1){
        y/=x;
        x/=x;
    }
    }
    }
    
  
    //setter for Numerator
    reduced.setNumerator(x);
    
    //if numerator equals 0 the denominator is automatically 1
      if (x == 0){
        reduced.setDenominator(1); 
    }else{
  
    reduced.setDenominator(y);
    }
    //returns object of 1
    return reduced;
}

//prints the fractions
void Rational::print(){
    cout << numerator << "/" << denominator << " ";
}

//checks to see if two fractions are equal to each other
bool Rational::equal(Rational num){
    
    num = num.reduction();
    
    if (numerator == num.getNumerator() && denominator == num.getDenominator()){
        return true;
    }
    
    return false;
}


//add two fractions together
Rational Rational::add(Rational num){
    Rational add;
 
 //calculates denominator and multiplies respective numeraters appropriately
    int common_denominator =   denominator * num.getDenominator();
    int new_numerator1 = numerator*num.getDenominator();
    int new_numerator2 = num.getNumerator()*denominator;
    
    //set numerator
    add.setNumerator(new_numerator1 + new_numerator2);
    //set denominator
    add.setDenominator(common_denominator);
    
    //reduces function
    add = add.reduction();
    
    //returns object
    return add;
}
