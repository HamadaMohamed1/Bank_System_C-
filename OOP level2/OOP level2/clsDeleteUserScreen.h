#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsDeleteUserScreen : protected clsScreen
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

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("   Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUserCard(User);
        cout << "Are you sure to delete this User ? y/n" << endl;
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            if (User.Delete())
            {
                cout << "User deleted successfuly" << endl;
                _PrintUserCard(User);
            }
            else
            {
                cout << "Error User was not deleted" << endl;
            }
        }
    }
};

