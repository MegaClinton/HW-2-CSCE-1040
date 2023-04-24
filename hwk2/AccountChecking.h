#ifndef ACCOUNTCHECKING_H
#define ACCOUNTCHECKING_H

#include "Account.h"

class AccountChecking : public Account
{
public:
    AccountChecking();
    ~AccountChecking();
    AccountChecking(const AccountChecking& origAccount);
    AccountChecking& operator=(const AccountChecking& origAccount);

    AccountChecking& operator+=(Account& srcAcct);

    void Deposit(float transaction);
    void Withdraw(float transaction);

    float getTransactionFee() const;
    void setTransactionFee(float transactionFee);

    void PrintInfo();

private:
    float transactionFee;
};
#endif
