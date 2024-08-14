#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermessions::pFindClient))
        {
            return; /*User Don't have permissions*/
        }

        _DrawScreenHeader("   Find Client Screen");

        cout << "\nPlease Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);

        if (client.IsEmpty())
        {
            cout << "\nClient Not Found\n" << endl;
        }
        else
        {
            cout << "\nClient Found\n" << endl;
        }

        _PrintClientCard(client);
        
        
	}


};

