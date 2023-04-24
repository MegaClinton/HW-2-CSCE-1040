#ifndef ACCOUNTSAVING_H
#define ACCOUNTSAVING_H

#include "Account.h"

class AccountSaving : public Account
{
public:
    AccountSaving();
    ~AccountSaving();
    AccountSaving(const AccountSaving& origAccount);
    AccountSaving& operator=(const AccountSaving& origAccount);

    AccountSaving& operator+=(AccountSaving& srcAcct);

    void Deposit(float transaction);
    void Withdraw(float transaction);

    float getMinimumBalance() const;
    void setMinimumBalance(float minimumBalance);

    void PrintInfo();

private:
    float minimumBalance;
};
#endif
