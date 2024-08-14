#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen
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
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "Enter FirstName: " << endl;
        Client.FirstName = clsInputValidate::ReadString();

        cout << "Enter LastName: " << endl;
        Client.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: " << endl;
        Client.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: " << endl;
        Client.Phone = clsInputValidate::ReadString();

        cout << "Enter PinCode: " << endl;
        Client.PinCode = clsInputValidate::ReadString();

        cout << "Enter Account Balance: " << endl;
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermessions::pUpdateClient))
        {
            return; /*User Don't have permissions*/
        }

        _DrawScreenHeader("   Update Client Screen");
        string AccountNumber = "";
        cout << "Please Enter client Account Number: " << endl;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::saveSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClientCard(Client1);
            break;
        }
        case clsBankClient::enSaveResults::saveFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }

};

