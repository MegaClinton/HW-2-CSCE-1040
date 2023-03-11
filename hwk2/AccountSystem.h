#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include "Accounts.h"

class AccountSystem
{
public:
    void Add();
    void Deposit();
    void Withdraw();
    void Transfer();
    void PrintAllAccounts();

private:
    Accounts accts;
};

#endif
