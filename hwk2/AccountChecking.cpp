#include "AccountChecking.h"

AccountChecking::AccountChecking()
{
    transactionFee = 0;
}
AccountChecking::~AccountChecking()
{
    transactionFee = -1;
}
AccountChecking::AccountChecking(const AccountChecking& origAccount) : Account(origAccount) //copyConstructor
{
    transactionFee = origAccount.getTransactionFee();
}
AccountChecking& AccountChecking::operator=(const AccountChecking& origAccount)
{
    if(this != &origAccount)
    {
        Account::operator=(origAccount);
        transactionFee = origAccount.getTransactionFee();
    }
    return *this;
}

AccountChecking& AccountChecking::operator+=(Account& srcAcct) //transfer operator
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
    cout << "Successfully transferred amount $" << transfer - getTransactionFee() << " from source account ID " << srcAcct.getId() << " to destination account ID " << this->getId() << endl;
    return *this;
}

void AccountChecking::Deposit(float transaction)
{
    Account::Deposit(transaction - transactionFee);
}
void AccountChecking::Withdraw(float transaction)
{
    Account::Withdraw(transaction + transactionFee);
}

float AccountChecking::getTransactionFee() const
{
    return transactionFee;
}

void AccountChecking::setTransactionFee(float transactionFee)
{
    this->transactionFee = transactionFee;
}

void AccountChecking::PrintInfo()
{
    Account::PrintInfo();
    cout << "Checking\t" << fixed << setprecision(2) << "$" << getTransactionFee() << endl;
}
