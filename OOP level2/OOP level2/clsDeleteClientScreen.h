#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDeleteClientScreen : protected clsScreen
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

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermessions::pDeleteClient))
        {
            return; /*User Don't have permissions*/
        }

        _DrawScreenHeader("   Delete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(client);
        cout << "Are you sure to delete this client ? y/n" << endl;
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            if (client.Delete())
            {
                cout << "Client deleted successfuly" << endl;
                _PrintClientCard(client);
            }
            else
            {
                cout << "Error Client was not deleted" << endl;
            }
        }
    }

};

