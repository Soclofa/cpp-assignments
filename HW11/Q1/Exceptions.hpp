//
//  Exceptions.hpp
//  Homework 11
//
//  Created by Avi Soclof on 6/9/22.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdio.h>

#include <exception>

class exceptionFamilyNumber : public exception{
    
    virtual const char* what() const throw(){
        return "ERROR: Invalid family number\n";
    }
}efn;

class exceptionDuplicateFamily : public exception{
    virtual const char* what() const throw(){
        return "ERROR: Family is already in the file\n";
    }
}edf;

class exceptionFamilyNotFound: public exception{
    virtual const char* what() const throw(){
        return "ERROR: Family is not in the file\n";
    }
}efnf;



#endif /* Exceptions_hpp */
