#pragma once
#include"clsScreen.h"
#include"clsUser.h"

class clsLoginRegisterScreen :protected clsScreen
{
private:
	static void _PrintRecord(clsUser::stLoginRegisterRecord record)
	{
		cout << " \t\t| " << left << setw(20) << record.date_time;
		cout << " \t\t| " << left << setw(20) << record.user_name;
		cout << " \t\t| " << left << setw(20) << record.permesseions << endl;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pLoginRegister))
		{
			return; /*User Don't have permissions*/
		}
		system("cls");
		vector <clsUser::stLoginRegisterRecord> loginVect = clsUser::GetLoginRegisterList();
		_DrawScreenHeader("\tLogin Register List Screen", "\t(" + to_string(loginVect.size()) + ") Users");
		cout << " \t\t-----------------------------------------------------------------------------" << endl;
		cout << " \t\t| " << left << setw(20) << "Date/Time";
		cout << " \t\t| " << left << setw(20) << "User Name";
		cout << " \t\t| " << left << setw(20) << "Permissions" << endl;
		cout << " \t\t-----------------------------------------------------------------------------" << endl;

		if (loginVect.size() == 0)
		{
			cout << "\t\t\t\tThere are no Users" << endl;
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& user : loginVect)
			{
				_PrintRecord(user);
			}
		}
		cout << " \t\t------------------------------------------------------------------------------" << endl;
		
	}


};

