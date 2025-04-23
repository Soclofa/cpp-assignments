//
//  Commander.hpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#ifndef Commander_hpp
#define Commander_hpp

#include <stdio.h>
#include "PrivateSoldier.hpp"
class Commander: public PrivateSoldier{
protected:
    bool isCombat;
    
public:
    Commander();
    Commander(int, string, string, int);
    Commander (const Commander&);
    bool getCombat(); 
    void print() const override;
    bool medal() const override;
    const string soldierType() const override;
    
    
    
};

#endif /* Commander_hpp */
