#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
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
    
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermessions::pAddNewClient))
        {
            return; /*User Don't have permissions*/
        }

        _DrawScreenHeader("   Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::saveSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClientCard(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::saveFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::saveFaildAccountNumberExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};

