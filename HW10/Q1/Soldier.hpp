//
//  Soldier.hpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#ifndef Soldier_hpp
#define Soldier_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;





class Soldier {
    
protected:
    
    int id;
    string first;
    string last;
    int numOperations;
    

public:
    Soldier();
    Soldier(int,string, string, int);
    Soldier(const Soldier&);
    virtual ~Soldier() {};
    virtual bool medal()const = 0;
    virtual void print() const;
    virtual const string soldierType()const = 0;
    
    //setters
    void setId(int);
    void setFirst(string);
    void setLast(string);
    void setNumOperations(int);
  
    //getters
    int getId() const;
    string getFirst() const;
    string getLast() const;
    int getNumOperations() const;
    


    
};

#endif /* Soldier_hpp */
