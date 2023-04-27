#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"
#include <vector>
#include "AccountChecking.h"
#include "AccountSaving.h"

class Accounts
{
public:
    void Add(Account *account);
    Account& findID(const int ID);
    Account& at(const int i) ;

    int getSize() const;

    void loadAccounts();
    void storeAccounts();
private:
    //Account* accounts;
    vector<Account*> accounts;
};

#endif
