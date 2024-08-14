#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{
private:
    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "******************************************************************" << endl;
        cout << "                          Client Card                             " << endl;
        cout << "******************************************************************" << endl;
        cout << "Name           : " << Client.GetFullName() << endl;
        cout << "Email          : " << Client.GetEmail() << endl;
        cout << "Phone          : " << Client.GetPhone() << endl;
        cout << "Account Number : " << Client.GetAccountNumber() << endl;
        cout << "Pin Code       : " << Client.GetPinCode() << endl;
        cout << "Balance        : " << Client.GetAccountBalance() << endl;
        cout << "******************************************************************\n" << endl;
    }

public:
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("   Withdraw Screen");

        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(client);

        double amount;
        cout << "Please enter withdraw amount" << endl;
        amount = clsInputValidate::ReadDoubleNumber("Enter valid amount");

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (client.Withdraw(amount))
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw , insufficeint balance\n";
                cout << "\nAmount to withdraw is : "<< amount<<endl;
                cout << "\nYour balance is : "<< client.AccountBalance<<endl;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};


