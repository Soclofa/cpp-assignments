//
//  Account.hpp
//  Clock
//
//  Created by Avi Soclof on 3/23/22.
//

#ifndef Account_h
#define Account_h

#include <stdio.h>
#include "Clock.hpp"

class Account {
    
    private:
    
    //fields
    int accountNumber;
    int code;
    float balance;
    string email;
    
    int digits(int num);
    
    //static fields
    static int sumWithdraw;
    static int sumDeposit;
    
    public:
    
    Account();
    Account(int, int, float, string);
    
    //setter
    void setBalance(float);
    void setEmail(string);
    //getter
    int getAccountNumber();
    int getCode();
    float getBalance();
    string getEmail();
    
    //user actions
    void withdraw (int);
    void deposit (int);
    
    //operators overloading
    friend istream& operator>> (istream&, Account&);
    
    //static methods
    static int getSumWithdraw();
    static int getSumDeposit();
};

#endif /* Account_hpp */
