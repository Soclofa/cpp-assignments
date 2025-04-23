//
//  Officer.hpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#ifndef Officer_hpp
#define Officer_hpp

#include <stdio.h>
#include "Soldier.hpp"
class Officer : public Soldier{
protected:
    int socio;
    
public:
    Officer();
    Officer(int, string , string, int);
    Officer(const Officer&);
    
    bool medal() const override;
    const string soldierType() const override;
   

    void print() const override;
    int getSocio() const; 
    
};

#endif /* Officer_hpp */
