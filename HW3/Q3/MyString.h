//
//  String.hpp
//  MyString
//
//  Created by Avi Soclof on 3/10/22.
//

#ifndef MyString_hpp
#define MyString_hpp

// MyString.h


#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

class MyString
{
    int len = 0;
    char* str;
public:
    //getters and setters
    char* getData() const;
    int getLength() const;
    void setData(char*);
    void setLength(int);

    MyString() : str(nullptr), len(0) {} //explicit empty constructor
    MyString(const char* s); //constructor
    MyString(const MyString& ms); //copy constructor
    MyString& operator=(const MyString& ms); //assignment operator
    ~MyString(); //destructor

    MyString(MyString&& ms); // move constructor
    MyString& operator=(MyString&& ms); //move assignment operator



    bool operator==(const MyString& ms) const;
    bool operator!=(const MyString& ms) const;
    bool operator>(const MyString& ms) const;
    bool operator<(const MyString& ms) const;
    bool operator>=(const MyString& ms) const;
    bool operator<=(const MyString& ms) const;
    MyString&  operator+(const MyString& ms) const;
    MyString&  operator* (const int) const;
    char& operator[] (const int index);

    friend ostream& operator<<(ostream& os, const MyString& ms);
    friend istream& operator>>(istream& is, MyString& ms);

    MyString insert(int index, const char* str);
};

    

#endif /* String_hpp */
