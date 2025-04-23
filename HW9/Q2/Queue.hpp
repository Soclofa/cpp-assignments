//
//  Queue.hpp
//  BST
//
//  Created by Avi Soclof on 6/01/22.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "QueueVector.hpp"
#include <iostream>

using namespace std;
template<class T>
class Queue
{
public:
    virtual ~Queue() {};
    virtual void clear() = 0;
    virtual void enqueue(T value) = 0;
    virtual T dequeue() = 0;
    virtual T front() = 0;
    virtual bool isEmpty() const = 0;
};


#endif /* Queue_hpp */
