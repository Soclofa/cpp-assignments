//Abraham Soclof 674098915
//Homework 4 
//Program includes two Classes: Clock and Account
//Account allows for user actions such as to  deposit and withdraw from their account and increments Clock for every action
#include "Account.hpp"
#include "Clock.hpp"

enum ACTION {
    STOP,
    BALANCE,
    DEPOSIT,
    WITHDRAW,
    SUM_DEPOSIT,
    SUM_WITHDRAW
};
ACTION menu() {
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to deposit money" << endl;
    cout << "enter 3 to withdraw money" << endl;
    cout << "enter 4 to see the sum of all deposits" << endl;
    cout << "enter 5 to see the sum of all withdrawals" << endl;
    cout << "enter 0 to stop" << endl;
    int x;
    cin >> x;
    return (ACTION)x;
}
int findAccount(Account* bank, int size) {
    int number, code;
    cout << "please enter account number:\n";
    cin >> number;
    int i = 0;
    while (i < size && bank[i].getAccountNumber() != number)
        i++;
    if (i >= size)
        throw "ERROR: no such account number\n";
    cout << "please enter the code:\n";
    cin >> code;
    if (bank[i].getCode() == code)
        return i;
    throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
    cout << c << "\t";
    switch (ac) {
    case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
        cout << "balance: " << a.getBalance() << endl;
        break;
    case DEPOSIT:
    case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
        cout << "new balance: " << a.getBalance() << endl;
        break;
    case SUM_DEPOSIT:
        cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
        break;
    case SUM_WITHDRAW:
        cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
        break;
    }
}
void getBalance(Account* bank, int size, Clock& c) {
    int i;
    try
    {
        i = findAccount(bank, size);
    }
    catch (const char*)
    {
        throw;
    }

    c += 20;
    printTransaction(bank[i], BALANCE, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {
    int i;
    try
    {
        i = findAccount(bank, size);
    }
    catch (const char*)
    {
        throw;
    }
    float amount;
    cout << "enter the amount of the deposit:\n ";
    cin >> amount;
    try
    {
        bank[i].deposit(amount);
    }
    catch (const char*)
    {
        throw;
    }
    c += 30;
    printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
    int i;
    try
    {
        i = findAccount(bank, size);
    }
    catch (const char*)
    {
        throw;
    }
    float amount;
    cout << "enter the amount of money to withdraw:\n ";
    cin >> amount;
    try
    {
        bank[i].withdraw(amount);
    }
    catch (const char*)
    {
        throw;
    }
    c += 50;
    printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
    for (int j = 0; j < i; j++)
        if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
            throw "ERROR: account number must be unique!\n";
}
int main() {
    const int SIZE = 10;

    Clock c(8, 0, 0);

    Account bank[SIZE];
    cout << "enter account number, code and email for " << SIZE << " accounts:\n";
    for (int i = 0; i < SIZE; i++) {
        try {
            cin >> bank[i];
            checkAccount(bank, i);
        }
        catch (const char* msg) {
            cout << c << '\t' << msg;
            i--;
        }
    }
    
    ACTION ac = menu();
    while (ac) {
        switch (ac) {
        case BALANCE:
            try
            {
                getBalance(bank, SIZE, c);
            }
            catch (const char* msg)
            {
                cout << c << '\t' << msg;
            }
            break;
        case WITHDRAW:
            try
            {
                cashWithdraw(bank, SIZE, c);
            }
            catch (const char* msg)
            {
                cout << c << '\t' << msg;
            }
            break;
        case DEPOSIT:
            try
            {
                cashDeposit(bank, SIZE, c);
            }
            catch (const char* msg)
            {
                cout << c << '\t' << msg;
            }
            break;
        case SUM_DEPOSIT:c += 60;
            printTransaction(bank[0], SUM_DEPOSIT, c);
            break;
        case SUM_WITHDRAW:c += 60;
            printTransaction(bank[0], SUM_WITHDRAW, c);
        }

        ac = menu();
    }

    return 0;
}

/*enter account number, code and email for 2 accounts:
1 1234 hello@gmail.com
2 1357 soclof@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2
please enter account number:
1
please enter the code:
1234
enter the amount of the deposit:
 200
08:00:30
	account #: 1	new balance: 200
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3
please enter account number:
1
please enter the code:
1234
enter the amount of money to withdraw:
 100
08:01:20
	account #: 1	new balance: 100
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
4
08:02:20
	sum of all deposits: 200
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
5
08:03:20
	sum of all withdrawals: -100
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
0
*/
