#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"

class Accounts
{
public:
    Accounts();
    ~Accounts();

    void Add(const Account& account);
    Account& findID(const int ID) const;
    Account& at(const int i) const;

    int getSize() const;

private:
    const int MAX_SIZE = 1000;
    Account* accounts;
    int size;
};

#endif
