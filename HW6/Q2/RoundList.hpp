//
//  RoundList.hpp
//  Homework 6 Question 2
//
//  Created by Avi Soclof on 4/3/22.
//

#ifndef RoundList_hpp
#define RoundList_hpp
#include "List.hpp"
#include <stdio.h>


class RoundList : public List
{

public:
    
    RoundList(); //
    RoundList(const RoundList&); //
    ~RoundList(); //
    void clear(); //
    void add(int); //
    
    void addToEnd(int);
    
    int search(int); //
    void removeFirst(); //
    bool isEmpty(); //
    
    friend ostream& operator << (ostream&, RoundList&);
    
};


#endif /* RoundList_hpp */
