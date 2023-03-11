#include "AccountSystem.h"
#include <iomanip>

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
    Account account;
    string name;
    float deposit;
    cout << "Enter customer account name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter initial deposit amount: $"; cin >> deposit;
    cin.ignore();

    account.setId(id);
    account.setName(name);
    account.setBalance(deposit);
    accts.Add(account);
    cout << "Added new account id " << account.getId() << " with initial balance $" << fixed << setprecision(2) << account.getBalance() << endl;
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
                cout << "Deposited $" << fixed << setprecision(2) << deposit << " into account id " << accts.at(i).getId() << endl;
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
                    cout << "Withdrawn $" << fixed << setprecision(2) << withdraw << " from account id " << accts.at(i).getId() << endl;
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
        cout << "Acct\tName\tBalance" << endl;
        cout << "----------------------------------------------------------" << endl;
        for(int i = 0; i < accts.getSize(); i++)
        {
            cout << accts.at(i).getId() << "\t" << accts.at(i).getName() << "\t" << fixed << setprecision(2) << "$" << accts.at(i).getBalance() << endl;
        }
    }
}