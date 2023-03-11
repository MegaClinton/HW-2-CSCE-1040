#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account
{
public:
    Account();
    ~Account();
    Account(const Account& origAccount);
    Account& operator=(const Account& origAccount);

    Account& operator+=(Account& srcAcct);

    void Deposit(float transaction);
    void Withdraw(float transaction);

    int getId() const;
    void setId(int id);
    string getName() const;
    void setName(string name);
    float getBalance() const;
    void setBalance(float balance);

private:
    int* ID;
    string name;
    float balance;
};

#endif
