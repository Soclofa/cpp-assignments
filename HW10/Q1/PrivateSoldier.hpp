//
//  PrivateSoldier.hpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#ifndef PrivateSoldier_hpp
#define PrivateSoldier_hpp

#include <stdio.h>
#include "Soldier.hpp"

class PrivateSoldier: public Soldier{
protected:
    int* grades;
public:
    PrivateSoldier();
    PrivateSoldier(int,string, string, int);
    PrivateSoldier(const PrivateSoldier&);
    virtual ~PrivateSoldier();
    
    void print() const override;
    const string soldierType() const override;
    bool medal() const override;
};

#endif /* PrivateSoldier_hpp */
