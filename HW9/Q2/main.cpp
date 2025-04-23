//
//  main.cpp
//  Library
//
//  Created by Avi Soclof on 6/01/22.
//  code has book class that using the bst allows user to input, remove, search, and print the books in a library 
#include "Library.hpp"
#include "SearchTree.hpp"
#include "Tree.hpp"
#include <iostream>

int main(){
    
    //create a SearchTree with data type of Book
    SearchTree <Book> library;
    //create an instance of book
    Book book;
    
    char input;
    enum {ENTER = 'a', REMOVE = 'b', SEARCH = 'c', PRINT = 'd', EXIT ='e'};
    cout << "enter a-e:" << endl;
    cin >> input;
    
    while (input != EXIT){
      
        switch (input){
                
                //enter a book and add it to the library
            case ENTER:
                cout << "enter a book:" << endl;
                cin >> book;
                library.add(book);
                break;
                //remove a book
            case REMOVE:
                cout << "enter a book:" << endl;
                cin >> book;
                if (library.search(book)){
                    library.remove(book);
                }
                else {
                    cout << "not exist" << endl;
                }
                break;
                //search for a book
            case SEARCH:
                cout << "enter a book:" << endl;
                cin >> book;
                if (library.search(book))
                {
                    cout << "exist" << endl;
                }
                else
                {
                    cout << "not exist" << endl;
                }
                break;
                //print the library
            case PRINT:
                library.inOrder();
                break;
                //prints error if user input is incorrect
            default:
                cout << "error" << endl;
                break;
        }
        cout << "enter a-e:" << endl;
        cin >> input;
    }
    return 0;
}

/*
enter a-e:
a
enter a book:
1 a a
enter a-e:
a
enter a book:
2 b b
enter a-e:
a
enter a book:
3 c c 
enter a-e:
a
enter a book:
4 d d 
enter a-e:
b
enter a book:
1 a a
enter a-e:
c
enter a book:
3 c c
exist
enter a-e:
c
enter a book:
1 a a
not exist
enter a-e:
d
2 b b
 3 c c
 4 d d
 enter a-e:
e
*/
