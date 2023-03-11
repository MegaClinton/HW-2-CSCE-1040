#include "Accounts.h"

Accounts::Accounts() //default constructor
{
    accounts = new Account[MAX_SIZE];
    size = 0;
}
Accounts::~Accounts() //destructor
{
    delete []accounts;
    size = 0;
}
void Accounts::Add(const Account& account)
{
    size++;
    accounts[size - 1] = account;
}
Account& Accounts::findID(const int ID) const//returns reference of account based on ID
{
    for(int i = 0; i < size; i++)
    {
        if(accounts[i].getId() == ID)
        {
            return accounts[i];
        }
    }
    throw;
}
Account& Accounts::at(const int i) const //returns reference of element in array
{
    if(i >= 0 && i < size)
    {
        return accounts[i];
    }
    throw;
}

int Accounts::getSize() const
{
    return size;
}




