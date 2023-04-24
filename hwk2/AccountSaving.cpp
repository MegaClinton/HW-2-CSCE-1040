#include "AccountSaving.h"

AccountSaving::AccountSaving()
{
    minimumBalance = 0;
}
AccountSaving::~AccountSaving()
{
    minimumBalance = -1;
}
AccountSaving::AccountSaving(const AccountSaving& origAccount) : Account(origAccount) //copy Constructor
{
    minimumBalance = origAccount.getMinimumBalance();
}
AccountSaving& AccountSaving::operator=(const AccountSaving& origAccount) //copy assignment operator
{
    if(this != &origAccount)
    {
        Account::operator=(origAccount);
        minimumBalance = origAccount.getMinimumBalance();
    }
    return *this;
}
AccountSaving& AccountSaving::operator+=(AccountSaving& srcAcct)
{
    cout << "Enter the transfer amount: $";
    float transfer;
    cin >> transfer;
    if(transfer > srcAcct.getBalance())
    {
        cout << "Not enough funds to transfer from account id " << srcAcct.getId() << endl;
        return *this;
    }
    if((srcAcct.getBalance() - transfer) < srcAcct.getMinimumBalance())
    {
        cout << "Error: Failed to withdraw $" << transfer << "from account id due to minimum balance" << srcAcct.getId() << endl;
        return *this;
    }
    else
    {
        srcAcct.Withdraw(transfer);
        this->Deposit(transfer);
        cout << "Successfully transferred amount $" << transfer  << " from source account ID " << srcAcct.getId()
             << " to destination account ID " << this->getId() << endl;
        return *this;
    }
}

void AccountSaving::Deposit(float transaction)
{
    if((getBalance() + transaction) < getMinimumBalance())
    {
        cout << "Error: Failed to deposit $" << transaction << "to account id " << getId() << endl;
    }
    else
    {
        Account::Deposit(transaction);
    }
}
void AccountSaving::Withdraw(float transaction)
{
    if((getBalance() - transaction) < getMinimumBalance())
    {
        cout << "Error: Failed to withdraw $" << transaction << "from account id " << getId() << endl;
    }
    else
    {
        Account::Withdraw(transaction);
    }
}
float AccountSaving::getMinimumBalance() const
{
    return minimumBalance;
}
void AccountSaving::setMinimumBalance(float minimumBalance)
{
    this->minimumBalance = minimumBalance;
}

void AccountSaving::PrintInfo()
{
    Account::PrintInfo();
    cout << "Saving\t\t" << fixed << setprecision(2) << "$" << getMinimumBalance() << endl;
}
