#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"


class clsTransferScreen :protected clsScreen
{
private:
    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "******************************************************************" << endl;
        cout << "                          Client Card                             " << endl;
        cout << "******************************************************************" << endl;
        cout << "Name           : " << Client.GetFullName() << endl;
        cout << "Balance        : " << Client.GetAccountBalance() << endl;
        cout << "******************************************************************\n" << endl;
    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("   Transfer Screen");

        cout << "\nPlease Enter Account Number to transfer from: ";
        string AccountNumber1 = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient Is Not Found, Choose another one: ";
            AccountNumber1 = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber1);
        _PrintClientCard(client1);
        
        cout << "\nPlease Enter Account Number to transfer to: ";
        string AccountNumber2 = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nClient Is Not Found, Choose another one: ";
            AccountNumber2 = clsInputValidate::ReadString();
        }
        clsBankClient client2 = clsBankClient::Find(AccountNumber2);
        _PrintClientCard(client2);

        double amount;
        cout << "Enter transfer amount" << endl;
        amount = clsInputValidate::ReadDoubleNumber("Enter valid amount");

        cout << "\nAre you sure you want to perform this operation? y/n";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            while (!client1.Transfer(amount , client2 , CurrentUser.UserName))
            {
                cout << "\nAmount Exceeds the available balance , Enter valid amount" << endl;
                amount = clsInputValidate::ReadDoubleNumber("Enter valid amount");
            }
            cout << "\nOperation done successfully" << endl;
        }
        else
        {
            cout << "\nOperation was cancelled.\n" << endl;
        }
        _PrintClientCard(client1);
        _PrintClientCard(client2);
    }
	
};

