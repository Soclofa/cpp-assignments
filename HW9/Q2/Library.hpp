//
//  Library.hpp
//  Library
//
//  Created by Avi Soclof on 6/01/22.
//

#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Book {
    
private:
    int bookNumber;
    string authorName;
    string bookName;
    
public:
    Book();
    bool operator > (const Book&)const;
    bool operator < (const Book&)const;
    bool operator <= (const Book&)const;
    bool operator >= (const Book&) const;
    bool operator == (Book&);
    bool operator != (Book&);

    
    friend ostream& operator << (ostream&, const Book&) ;
    friend istream& operator >> (istream&,  Book&);
    
};






#endif /* Library_hpp */
