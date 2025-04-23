//
//  Rational.cpp
//  Homework Assignment #1
//
//  Created by Avi Soclof on 2/20/22.
//


#include "Rational.h"

//private methods
int Rational::commonDenominator(const Rational r2) const{
    
    return denominator * r2.getDenominator();
    
}

    //reduces the fraction
    Rational Rational::reduction() const{
      
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



//Public methods
Rational::Rational()
{
    numerator = 1;
    denominator = 1;
}

Rational::Rational(int num, int den)
{
    numerator = num;
    denominator = den;
}

Rational::Rational(const Rational& r2) {
    numerator = r2.numerator;
    denominator = r2.denominator;
}

//setter for Numerator
void Rational::setNumerator(int _numerator)
{
    numerator = _numerator;
}

//setter for Denominator
void Rational::setDenominator(int _denominator) {
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
int Rational::getNumerator() const{
    return numerator;
}

//getter for denominator
int Rational::getDenominator() const{
    return denominator;
}


//prints the fractions
void Rational::print() const{
    if (denominator == 1){
        cout << numerator;
    }else{
    cout << numerator << "/" << denominator << " ";
    }
}


                        //OPERATORS METHODS//

//add two fractions together
Rational Rational::operator + (const Rational& newRational) const{
    

 //calculates denominator and multiplies respective numeraters appropriately
    int new_numerator1 = numerator*newRational.getDenominator();
    int new_numerator2 = newRational.getNumerator()*denominator;
    
    Rational add (new_numerator1 + new_numerator2,commonDenominator(newRational));
    
    //reduces function
    add = add.reduction();
    
    //returns object
    return add;
}


Rational Rational:: operator - (const Rational& newRational) const{
    int new_numerator1 = numerator*newRational.getDenominator();
    int new_numerator2 = newRational.getNumerator()*denominator;
    
    Rational subtract (new_numerator1 - new_numerator2, commonDenominator(newRational) );
    
    subtract = subtract.reduction();

    return subtract;
}

Rational Rational::operator /(const Rational& newRational) const{
    
    Rational divide (numerator*newRational.denominator, denominator*newRational.numerator);
    
   divide =  divide.reduction();
    
    return divide;
}

Rational Rational::operator * (const Rational &newRational) const{
    
    Rational multiply (numerator*newRational.numerator, denominator*newRational.denominator);
    
    multiply = multiply.reduction();
    
    return multiply; 
}



//boolean operators
bool Rational::operator==(const Rational& num) const {
    Rational temp1 = *this;
    Rational temp2 = num;
    temp1.reduction();
    temp2.reduction();
    return temp1.numerator == temp2.numerator && temp1.denominator == temp2.denominator;
}


bool Rational::operator != (const Rational& num) const{
    return !(*this == num);
}


bool Rational:: operator <(const Rational& r2) const
{
    return (numerator * r2.denominator) - (denominator * r2.numerator) < 0 ;
}
 
bool Rational::operator > (const Rational& r2) const
{
    return (numerator * r2.denominator) - (denominator *r2.numerator) > 0;
}


bool Rational::operator <= (const Rational& r2) const{
    if (*this == r2 || *this < r2){
        return true;
    }
    return false;
}

bool Rational::operator >= (const Rational& r2) const{
    if (*this == r2 || *this > r2){
        return true;
    }
    
    return false;
}



//post incre/decre

Rational Rational::operator ++(int){
   
    Rational temp(*this);
    numerator = numerator + denominator;
    return temp;
}
    
Rational& Rational::operator++(){
    numerator = numerator + denominator;
    return *this;
}

Rational Rational::operator--(int){
    Rational temp(*this);
    numerator = numerator - denominator;
    return temp;
}

Rational& Rational::operator-- (){
    numerator = numerator - denominator;
    return *this;
}
