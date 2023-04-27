#include "Accounts.h"

void Accounts::Add(Account* account)
{
    accounts.push_back(account);
}
Account& Accounts::findID(const int ID)//returns reference of account based on ID
{
    for(auto & account : accounts)
    {
        if(account->getId() == ID)
        {
            return *account;
        }
    }
    throw;
}
Account& Accounts::at(const int i) //returns reference of element in array
{
    return *(accounts.at(i));
}

int Accounts::getSize() const
{
    return accounts.size();
}

void Accounts::loadAccounts() //read info from file and store inside vector
{
    ifstream fin;
    fin.open("accounts.dat");
    if(fin.fail())
    {
        cout << "Note: accounts.dat file not found." << endl;
        return;
    }
    int size;
    fin >> size;
    for (int i = 0; i < size; i++)
    {
        int ID;
        int accountType;
        fin >> ID;
        fin >> accountType;
        if(accountType == 1)
        {
            AccountChecking* acc = new AccountChecking;
            float transactionFee;
            float balance;
            string name;
            fin >> transactionFee;
            fin >> balance;
            getline(fin >> ws,name);
            acc->setId(ID);
            acc->setAccountType(accountType);
            acc->setTransactionFee(transactionFee);
            acc->setBalance(balance);
            acc->setName(name);
            accounts.push_back(acc);
        }
        if(accountType == 2)
        {
            AccountSaving* acc = new AccountSaving;
            float minimumBalance;
            float balance;
            string name;
            fin >> minimumBalance;
            fin >> balance;
            getline(fin >> ws,name);
            acc->setId(ID);
            acc->setAccountType(accountType);
            acc->setMinimumBalance(minimumBalance);
            acc->setBalance(balance);
            acc->setName(name);
            accounts.push_back(acc);
        }
    }
    fin.close();
}
void Accounts::storeAccounts() //write info from vector to file
{
    ofstream fout;
    fout.open("accounts.dat");
    if(fout.fail())
    {
        cout << "Note: accounts.dat file not found." << endl;
        return;
    }
    fout << accounts.size() << endl;
    for(auto &&account : accounts)
    {
        account->store(fout);
    }
    fout.close();
}




