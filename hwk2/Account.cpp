#include "Account.h"

Account::Account() //default constructor
{
    ID = new int;
    *ID = -1;
    name = "unknown";
    balance = 0;
    accountType = 0;
}
Account::~Account() //destructor
{
    delete ID;
}
Account::Account(const Account& origAccount) //copy constructor
{
    ID = new int;
    *ID = origAccount.getId();
    name = origAccount.getName();
    balance = origAccount.getBalance();
    accountType = origAccount.getAccountType();
}
Account& Account::operator=(const Account& origAccount) //copy assignment
{
    if(this != &origAccount)
    {
        delete ID;
        ID = new int;
        *ID = origAccount.getId();
        name = origAccount.getName();
        balance = origAccount.getBalance();
        accountType = origAccount.getAccountType();
    }
    return *this;
}

void Account::Deposit(float transaction) //adds to balance
{
    balance += transaction;
    cout << "Deposited $" << fixed << setprecision(2) << transaction << " into account id " << getId() << endl;
}

void Account::Withdraw(float transaction) //subtracts from balance
{
    balance -= transaction;
    cout << "Withdrawn $" << fixed << setprecision(2) << transaction << " from account id " << getId() << endl;
}

Account& Account::operator+=(Account& srcAcct) //transfer operator
{
    cout << "Enter the transfer amount: $";
    float transfer;
    cin >> transfer;
    if(transfer > srcAcct.getBalance())
    {
        cout << "Not enough funds to transfer from account id " << srcAcct.getId() << endl;
        return *this;
    }
    srcAcct.Withdraw(transfer);
    this->Deposit(transfer);
    cout << "Successfully transferred amount $" << transfer << " from source account ID " << srcAcct.getId() << " to destination account ID " << this->getId() << endl;
    return *this;
}

//getters & setters
int Account::getId() const
{
    return *ID;
}

void Account::setId(int id)
{
    *ID = id;
}

string Account::getName() const
{
    return name;
}
void Account::setName(string name)
{
    this->name = name;
}

float Account::getBalance() const
{
    return balance;
}

void Account::setBalance(float balance)
{
    this->balance = balance;
}

int Account::getAccountType() const
{
    return accountType;
}

void Account::setAccountType(int accountType)
{
    this->accountType = accountType;
}

void Account::PrintInfo()
{
    cout << getId() << "\t" << getName() << "\t" << fixed << setprecision(2) << "$" << getBalance() << "\t";
}

void Account::store(ofstream& fout)
{
    fout << getId() << " ";
    fout << getAccountType() << " ";
}



