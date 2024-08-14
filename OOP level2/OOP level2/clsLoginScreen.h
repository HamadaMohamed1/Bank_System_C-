#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool loginFail = false;
		string userName, password;
		short counter = 3;
		do 
		{
			if (loginFail == true)
			{
				cout << "Invalid username or password\n" << endl;
				if (--counter == 0)
				{
					return false;
				}
				cout << "You have " << counter << " Trials to login" << endl;
			}
			cout << "Enter UserName :" << endl;
			cin >> userName;
			cout << "Enter Password :" << endl;
			cin >> password;

			CurrentUser = clsUser::Find(userName,password);
			loginFail = CurrentUser.IsEmpty();
		} while (loginFail);
		/*recording the user*/
		CurrentUser.AddToLogfile();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		return _Login();
	}
};

