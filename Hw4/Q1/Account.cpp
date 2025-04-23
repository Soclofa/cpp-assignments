//
//  Account.cpp
//  Clock
//
//  Created by Avi Soclof on 3/23/22.
//

#include "Account.hpp"

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

Account::Account(){
    accountNumber = 0;
    code = 0;
    balance = 0;
    email = "";
}


Account::Account (int _accountNumber, int _code, float _balance, string _email){
    //checks for valid length of code
    if (digits(_code)!=4)
    {
        throw "ERROR: code must be of 4 digits!\n";
    }
    
    accountNumber = _accountNumber;
    code = _code;
    balance = _balance;
    email = _email;
}


void Account::setBalance(float b){
    balance = b;
}


//sets email checks for valid email input
void Account::setEmail(string _email){
    int AT_Index = (int)_email.find("@");
    int length =  (int)_email.length();
    
    int com_Index = (int)_email.find(".com");
    int IL_Index = (int)_email.find(".co.il");
    
    //checks if email contains @
    if (AT_Index == -1){
         throw "ERROR: email must contain @!\n";
    }
    
    //checks that @ is not the first char in the string
    if (AT_Index == 0){
        throw "ERROR: email must begin with a regular character!\n";
    }
    //checks that @ is not the last char of the string
    if (com_Index - 1 == AT_Index || IL_Index -1 == AT_Index){
        throw "ERROR: must have characters between @ and end!\n";
    }
    //checks for .com and .co.il
    if (_email.compare(length-4, 4, ".com") != 0 && _email.compare(length-6, 6, ".co.il")!= 0){
         throw "ERROR: email must end at .com or .co.il!\n";
    }
    
    email = _email;
}


//getter
int Account::getAccountNumber(){
    return accountNumber;
}
int Account::getCode(){
    return code;
}
float Account::getBalance(){
    return balance;
}
string Account::getEmail(){
    return email;
}

// static getters

int Account::getSumDeposit(){
    return sumDeposit;
}

int Account::getSumWithdraw(){
    return sumWithdraw;
}

//output stream
istream& operator >> (istream& is, Account& account){
    
    int newAccountNum;;
    int newCode;
    float newBalance;
    
    string _email;
    is >> newAccountNum >> newCode >> _email;
    
    if  (account.digits(newCode)!= 4) {
        throw "ERROR: code must be of 4 digits!\n";
    }
    
    try
    {
        account.setEmail(_email);
    }
    catch (const char* e){
        throw;
    }
    
    account.accountNumber = newAccountNum;
    account.code = newCode;
    account.balance = 0;
    
    return is;
}

//static count of withdrawal amount
void Account::withdraw(int amount){
    if (balance - amount < -6000 ){
        throw "ERROR: cannot have less than - 6000 NIS!\n";
    }
    if (amount > 2500 || amount < 0 ){
        throw "ERROR: cannot withdraw more than 2500 NIS!\n";
    }
    balance -= amount;
    sumWithdraw -= amount;
}

//static count of deposit amount
void Account::deposit(int amount){
    if (amount > 10000){
        throw "ERROR: cannot deposit more than 10000 NIS!\n";
    }
    balance += amount;
    
    sumDeposit += amount;
}


//checks if code is 4 digits
int Account::digits(int num){
    int digitCount = 0;
    
    while (num != 0){
        num/=10;
        digitCount++;
    }
    return digitCount;
}
