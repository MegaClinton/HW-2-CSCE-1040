#ifndef ACCOUNTCHECKING_H
#define ACCOUNTCHECKING_H

#include "Account.h"
#include "AccountSaving.h"

class AccountChecking : public Account
{
public:
    AccountChecking();
    ~AccountChecking();
    AccountChecking(const AccountChecking& origAccount);
    AccountChecking& operator=(const AccountChecking& origAccount);

    AccountChecking& operator+=(Account& srcAcct);
    AccountChecking& operator+=(AccountSaving& srcAcct);

    void Deposit(float transaction);
    void Withdraw(float transaction);

    float getTransactionFee() const;
    void setTransactionFee(float transactionFee);

    void PrintInfo();

    void store(ofstream &fout);

private:
    float transactionFee;
};
#endif
