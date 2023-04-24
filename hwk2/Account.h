#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>

using namespace std;

class Account
{
public:
    Account();
    ~Account();
    Account(const Account& origAccount);
    Account& operator=(const Account& origAccount);

    virtual Account& operator+=(Account& srcAcct);

    virtual void Deposit(float transaction);

    virtual void Withdraw(float transaction);

    int getId() const;
    void setId(int id);
    string getName() const;
    void setName(string name);
    float getBalance() const;
    void setBalance(float balance);

    int getAccountType() const;

    void setAccountType(int accountType);

    virtual void PrintInfo();

private:
    int* ID;
    string name;
    float balance;
    int accountType;
};

#endif
