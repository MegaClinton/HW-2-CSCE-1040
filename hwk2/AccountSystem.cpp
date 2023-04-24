#include "AccountSystem.h"

void AccountSystem::Add() //add account
{
    int id;
    cout << "Enter account id: "; cin >> id;
    for(int i = 0;i < accts.getSize(); i++)
    {
        if(accts.at(i).getId() == id) //if id already exists in accounts, do not create new account
        {
            cout << "This account already exists." << endl;
            return;
        }
    }
    int accountType;
    cout << "Enter account type (1: checking, 2: saving): "; cin >> accountType;
    if(accountType != 1 && accountType != 2)
    {
        cout << "Error: invalid account type. Account type (1: checking, 2: saving)" << endl;
        return;
    }
    if(accountType == 1)
    {
        AccountChecking* account = new AccountChecking;
        string name;
        float deposit;
        cout << "Enter customer account name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter initial deposit amount: $"; cin >> deposit;
        float transactionFee;
        cout << "Enter the transaction fee: $"; cin >> transactionFee;
        cin.ignore();

        account->setId(id);
        account->setName(name);
        account->setBalance(deposit);
        account->setTransactionFee(transactionFee);
        account->setAccountType(accountType);
        accts.Add(account);
        cout << "Added new account id " << account->getId() << " with initial balance $" << fixed << setprecision(2) << account->getBalance() << endl;
    }
    else if(accountType == 2)
    {
        AccountSaving* account = new AccountSaving;
        string name;
        float deposit;
        cout << "Enter customer account name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter initial deposit amount: $"; cin >> deposit;
        float minimumBalance;
        cout << "Enter the minimum balance: $"; cin >> minimumBalance;
        cin.ignore();

        account->setId(id);
        account->setName(name);
        account->setBalance(deposit);
        account->setMinimumBalance(minimumBalance);
        account->setAccountType(accountType);
        accts.Add(account);
        cout << "Added new account id " << account->getId() << " with initial balance $" << fixed << setprecision(2) << account->getBalance() << endl;
    }

}
void AccountSystem::Deposit() //deposit into an account
{
    if(accts.getSize() == 0)
    {
        cout << "Empty account list." << endl;
    }
    else
    {
        int id;
        cout << "Enter account id: ";
        cin >> id;
        for (int i = 0; i < accts.getSize(); i++)
        {
            if (accts.at(i).getId() == id)
            {
                float deposit;
                cout << "Enter the deposit amount: $";
                cin >> deposit;
                accts.at(i).Deposit(deposit);
                return;
            }
        }
        cout << "Error: account with id " << id << " not found." << endl;
    }
}
void AccountSystem::Withdraw() //withdraw from an account
{
    if(accts.getSize() == 0)
    {
        cout << "Empty account list." << endl;
    }
    else
    {
        int id;
        cout << "Enter account id: ";
        cin >> id;
        for (int i = 0; i < accts.getSize(); i++)
        {
            if (accts.at(i).getId() == id)
            {
                float withdraw;
                cout << "Enter the withdraw amount: $";
                cin >> withdraw;
                if(withdraw > accts.at(i).getBalance())
                {
                    cout << "Not enough funds to withdraw from account id " << accts.at(i).getId() << endl;
                    return;
                }
                else
                {
                    accts.at(i).Withdraw(withdraw);
                    return;
                }
            }
        }
        cout << "Error: account with id " << id << " not found." << endl;
    }
}
void AccountSystem::Transfer() //transfer money from one account to another
{
    if(accts.getSize() == 0)
    {
        cout << "Empty account list." << endl;
    }
    else
    {
        int srcId;
        int destId;
        bool src = false;
        bool dest = false;

        cout << "Enter source account id: "; cin >>srcId;
        cout << "Enter destination account id: "; cin >>destId;
        for(int i = 0;i < accts.getSize(); i++)
        {
            if(accts.at(i).getId() == srcId)
            {
                src = true;
            }
            if(accts.at(i).getId() == destId)
            {
                dest = true;
            }
        }
        if(src && dest)
        {
            accts.findID(destId) += accts.findID(srcId);
        }
        else
        {
            cout << "Error: Source or destination account number not found. Operation failed" << endl;
        }
    }
}
void AccountSystem::PrintAllAccounts() //print all account info
{
    if(accts.getSize() == 0)
    {
        cout << "Empty account list." << endl;
    }
    else
    {
        cout << "Acct\tName\t\tBalance\t\tType\t\tFee/Min" << endl;
        cout << "----------------------------------------------------------" << endl;
        for(int i = 0; i < accts.getSize(); i++)
        {
            accts.at(i).PrintInfo();
        }
    }
}

void AccountSystem::loadAccountSystem()
{
    accts.loadAccounts();
}
void AccountSystem::storeAccountSystem()
{
    accts.storeAccounts();
}