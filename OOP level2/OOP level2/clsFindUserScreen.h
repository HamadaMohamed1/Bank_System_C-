#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsFindUserScreen :protected clsScreen
{
private:
    static void _PrintUserCard(clsUser User)
    {
        cout << "******************************************************************" << endl;
        cout << "                          User Card                             " << endl;
        cout << "******************************************************************" << endl;
        cout << "User Name      : " << User.GetUserName() << endl;
        cout << "Full Name      : " << User.GetFullName() << endl;
        cout << "Email          : " << User.GetEmail() << endl;
        cout << "Phone          : " << User.GetPhone() << endl;
        cout << "Password       : " << User.Password << endl;
        cout << "Permissions    : " << User.Permissions << endl;
        cout << "******************************************************************\n" << endl;
    }
public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("   Find User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (User.IsEmpty())
        {
            cout << "\nUser Not Found\n" << endl;
        }
        else
        {
            cout << "\nUser Found\n" << endl;
        }

        _PrintUserCard(User);


    }
};

