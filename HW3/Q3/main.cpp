//
//  main.cpp
//  MyString
//
//  Created by Abraham Soclof on 3/10/22.
//    ID:674098915
// an addition to the string library which allows for insertion of a string at a certain index of another string and the insertion of a character to a particular index of a string.

#include "MyString.h"
using namespace std;

int main() {
    int n;
    char word1[20];
    char word2[20];
    char ch;
    cin >> word1;
    cin >> word2;
    cin >> n;
   
    MyString a(word1);
    MyString b(word2);

    if (a > b)
        cout << "a>b" << endl;
    if (a < b)
        cout << "a<b" << endl;
    if (a == b)
        cout << "a=b" << endl;

    MyString c;
    
    c = b.insert(n, a.getData());
    if (strcmp(c.getData(),"")){
    cout << c;
    }

    cin >> ch >> n;
    c[n] = ch;
    if (n >= 0 && n < c.getLength()) {
        cout << c;
    }


    return 0;
}


/*
 World
 Hello
 5
 a>b
 move ctor
 move assign
 HelloWorld
 !
 5
 Hello!orld

 
 
 
 
 
 */

