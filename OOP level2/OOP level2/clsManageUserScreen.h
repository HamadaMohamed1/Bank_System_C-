#pragma once
#include"iostream"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;

class clsManageUserScreen : protected clsScreen
{
private:

	enum enManageUsersOptions 
	{
		eListUsers = 1 , eAddNewUser , eDeleteUser , eUpdateUser , eFindUser , eMainMenue
	};
	static void _ListUsersScreen()
	{
		//cout << "_ListUsersScreen here" << endl;
		clsListUsersScreen::ShowUsersList();
	}
	static void _AddNewUserScreen()
	{
		//cout << "_AddNewUserScreen here" << endl;
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _DeleteUserScreen()
	{
		//cout << "_DeleteUserScreen here" << endl;
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _UpdateUserScreen()
	{
		//cout << "_UpdateUserScreen here" << endl;
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _FindUserScreen()
	{
		//cout << "_FindUserScreen here" << endl;
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _GoToBackToManageUserScreen()
	{
		cout << "\tPress Any Key to go to Manage user screen" << endl;
		system("pause>0");
		ShowManageUsersScreen();
	}

	static short _ReadManageUsersOption()
	{
		cout << "\t\t\t\tChoose what do you want to do ? [1 to 6]" << endl;
		short num = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter number between [1 to 6]");
		return num;
	}
	static void _PerfromManageUsersOption(enManageUsersOptions UsersOption)
	{
		switch (UsersOption)
		{
		case clsManageUserScreen::eListUsers:
			system("cls");
			_ListUsersScreen();
			_GoToBackToManageUserScreen();
			break;
		case clsManageUserScreen::eAddNewUser:
			system("cls");
			_AddNewUserScreen();
			_GoToBackToManageUserScreen();
			break;
		case clsManageUserScreen::eDeleteUser:
			system("cls");
			_DeleteUserScreen();
			_GoToBackToManageUserScreen();
			break;
		case clsManageUserScreen::eUpdateUser:
			system("cls");
			_UpdateUserScreen();
			_GoToBackToManageUserScreen();
			break;
		case clsManageUserScreen::eFindUser:
			system("cls");
			_FindUserScreen();
			_GoToBackToManageUserScreen();
			break;
		case clsManageUserScreen::eMainMenue:
			break;
		default:
			break;
		}

	}



public:

	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pManageUsers))
		{
			return; /*User Don't have permissions*/
		}
		system("cls");
		_DrawScreenHeader("\tManage Users Screen");
		cout << "\t\t\t\t=============================" << endl;
		cout << "\t\t\t\t  [1] List Users." << endl;
		cout << "\t\t\t\t  [2] Add New User." << endl;
		cout << "\t\t\t\t  [3] Delete User." << endl;
		cout << "\t\t\t\t  [4] Update User." << endl;
		cout << "\t\t\t\t  [5] Find User." << endl;
		cout << "\t\t\t\t  [6] Main Menue." << endl;
		cout << "\t\t\t\t=============================" << endl;
		_PerfromManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}


};

