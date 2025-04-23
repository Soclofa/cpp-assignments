//
//  StackVector.hpp
//  Homework8.1
//
//  Created by Avi Soclof on 4/28/22.
//

#ifndef StackVector_hpp
#define StackVector_hpp

#include <stdio.h>
#include "Vector.hpp"

//#include "Vector.h" //homework targil 2 !
//-------------------------------------------------------
// class StackVector
// Stack implemented using Vector
// Vector will grow as necessary to avoid overflow
//-------------------------------------------------------
template <class T> class StackVector
{
    
protected:
 // data fields
 Vector<T> data;
    
public:
 // constructor requires a starting size
 StackVector();
 StackVector(const StackVector<T>& source);

// Stack operations
 void clear();
 bool isEmpty() const;
 int pop();
 void push(T value);
 int top() ;
    

};

//-------------------------------------------------------
// class StackVector implementation
//-------------------------------------------------------

template <class T>
StackVector<T>::StackVector()
{}

template <class T>
StackVector<T>::StackVector(const StackVector<T>& s)
: data(s.data)
{}


template <class T>
void StackVector<T>::clear()
{
 // clear all elements from Stack, by setting
 // index to bottom of Stack
 data.clear();
}

template <class T>
bool StackVector<T>::isEmpty() const
{
 return data.isEmpty();
}

template <class T>
int StackVector<T>::pop()
{
// return and remove the intopmost element in the Stack
 if(isEmpty()) throw "Stack is empty";
    
 return data.delLast();
}

template <class T>
void StackVector<T>::push(T val)
{
 // push new value onto Stack
 data.insert(val);
}

template <class T>
int StackVector<T>::top() 
{
 // return the intopmost element in the Stack
 if(isEmpty()) throw "Stack is empty";
    return data[data.getSize()-1];
}

#endif /* StackVector_hpp */
