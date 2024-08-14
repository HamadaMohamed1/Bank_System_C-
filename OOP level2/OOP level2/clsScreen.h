#pragma once
#include <iostream>
#include <string>
#include"clsDate.h"
#include"clsUser.h"
#include"Global.h"

using namespace std;

class clsScreen
{
private:
	
protected:

	static void _DrawScreenHeader(string Title , string SubTitle = "")
	{
		cout << "\t\t\t\t___________________________________________" << endl;
		cout << "\t\t\t\t\t" << Title << endl;
		if(SubTitle !="")
			cout << "\t\t\t\t\t" << SubTitle << endl;
		cout << "\t\t\t\t___________________________________________" << endl;
		cout << "\t\t\t\tUser : " << CurrentUser.UserName << endl;
		cout << "\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl ;
		cout << "\t\t\t\t___________________________________________" << endl;
	}

	static bool CheckAccessRights(clsUser::enPermessions permessions)
	{
		if (!CurrentUser.CheckAccessPermission(permessions))
		{
			cout << "\t\t\t\t___________________________________________" << endl;
			cout << "\t\t\t\t\t" << "Access Denied, Contact your Admin" << endl;
			cout << "\t\t\t\t___________________________________________" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
};

