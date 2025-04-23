//
//  Library.cpp
//  Library
//
//  Created by Avi Soclof on 6/01/22.
//

#include "Library.hpp"
#include <cstring>
#include <string>
using namespace std;
#include <iostream>

//constructor 
Book::Book():bookNumber(0), authorName(""), bookName(""){}
  
 //overloading >
bool Book::operator > (const Book& b)const{
    
    //comparing author Names
    if (authorName.compare(b.authorName) < 0){
        return false;
    }
    else if (authorName.compare(b.authorName) > 0){
        return true;
    }
    
    //comparing book names
    if (bookName.compare(b.bookName) < 0){
        return false;
    }
    else if (bookName.compare(b.bookName) > 0){
        return true;
    }
    
    //comparing bookNumber
    if (bookNumber < b.bookNumber){
        return false;
    }
    else if (bookNumber > b.bookNumber){
        return true;
    }
    return false;
}

//overlaoding < 
bool Book::operator < (const Book& b) const{
    //comparing author Names
    if (authorName.compare(b.authorName) > 0){
        return false;
    }
    else if (authorName.compare(b.authorName) < 0){
        return true;
    }
    
    //comparing book names
    if (bookName.compare(b.bookName) > 0){
        return false;
    }
    else if (bookName.compare(b.bookName) < 0){
        return true;
    }
    
    //comparing bookNumber
    if (bookNumber > b.bookNumber){
        return false;
    }
    else if (bookNumber < b.bookNumber){
        return true;
    }
    
    return false;

}

//overloadding <=
bool Book::operator <= (const Book& b)const{
    return *(this) < b || this->authorName.compare(b.authorName) == 0;
}

//overlaoding >=
bool Book::operator >= (const Book& b) const{
return *(this) > b || this->authorName.compare(b.authorName) == 0;
}

//overlaoding == 
bool Book::operator == (Book& b){
    return authorName.compare(b.authorName) == 0 && bookName.compare(b.bookName) == 0 && bookNumber == b.bookNumber;
}

//overlaoding !=
bool Book::operator != (Book& b){
    return !(*(this) == b);
}

//overloading << output
ostream& operator << (ostream& os, const Book& b){
    os << b.bookNumber << " " << b.authorName << " " << b.bookName << endl;
    return os;
}

//overlaoding >> input
istream& operator>> (istream& is,  Book& b)
{
    is >> b.bookNumber >> b.authorName >> b.bookName;
    return is;
}

