#include "AccountSystem.h"
using namespace std;

int main()
{
    AccountSystem bank;

    cout << "Name: Clinton Nguyen\nEUID: cdn0116\nEmail: clintonnguyen@my.unt.edu\nCourse: CSCE 1040\nDepartment: Computer Science and Engineering\n" << endl;

    bank.loadAccountSystem();
    do
    {
        cout << endl;

        cout << endl;

        cout << "1. Add new account\n2. Deposit into account\n3. Withdraw from account\n4. Transfer into account\n5. Print a list of all accounts\n6. End transaction (Exit)\n" << endl;

        int choice;
        cout << "Enter account selection: "; cin >> choice;

        switch(choice)
        {
            case(1): //add account
            {
                bank.Add();
                break;
            }
            case(2): //deposit into an account
            {
                bank.Deposit();
                break;
            }
            case(3): //withdraw from an account
            {
                bank.Withdraw();
                break;
            }
            case(4): //transfer from one account to another
            {
                bank.Transfer();
                break;
            }
            case(5):
            {
                bank.PrintAllAccounts(); //print all accounts info
                break;
            }
            case(6): //exits program
            {
                cout << "Thank you for running the program. Goodbye!" << endl;
                bank.storeAccountSystem();
                exit(1);
            }
            default: //entered an invalid choice
            {
                cout << "Error: Invalid selection. Enter a value between 1-6." << endl;
            }
        }
    }
    while(true);
}
