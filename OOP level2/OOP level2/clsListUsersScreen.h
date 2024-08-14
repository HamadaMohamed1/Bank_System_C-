#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>

class clsListUsersScreen : protected clsScreen
{
private:
	static void PrintUser(clsUser user)
	{

		cout << " | " << left << setw(15) << user.UserName;
		cout << " | " << left << setw(20) << user.GetFullName();
		cout << " | " << left << setw(15) << user.Phone;
		cout << " | " << left << setw(18) << user.Email;
		cout << " | " << left << setw(15) << user.Password;
		cout << " | " << left << setw(15) << user.Permissions << endl;
	}
public:
	static void ShowUsersList()
	{
		vector <clsUser> UsersList = clsUser::GetUsersList();
		_DrawScreenHeader("\tUsers List Screen", "\t(" + to_string(UsersList.size()) + ") Users");
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;
		cout << " | " << left << setw(15) << "UserName";
		cout << " | " << left << setw(20) << "Full Name";
		cout << " | " << left << setw(15) << "Phone";
		cout << " | " << left << setw(18) << "Email";
		cout << " | " << left << setw(15) << "Password";
		cout << " | " << left << setw(15) << "Permissions" << endl;
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;

		if (UsersList.size() == 0)
		{
			cout << "\t\t\t\tThere are no Users" << endl;
		}
		else
		{
			for (clsUser& user : UsersList)
			{
				PrintUser(user);
			}
		}
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;
	}

};

