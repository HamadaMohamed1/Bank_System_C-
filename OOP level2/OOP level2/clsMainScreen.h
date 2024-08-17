#pragma once
#include "clsUtil.h"
#include"clsScreen.h"
#include"iomanip"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUserScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8 ,eCurrencyExchange = 9 ,eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << "\t\t\t\tChoose what do you want to do ? [1 to 10]" << endl;
		short num =clsInputValidate::ReadShortNumberBetween(1, 10, "Enter number between [1 to 10]");
		return num;
	}

	static void _GoToBackToMainMenue()
	{
		cout << "\tPress Any Key to go to main menue" << endl;
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowClientsListMenue()
	{
		clsClientListScreen::ShowCLientsList();
	}
	static void _AddNewClientMenue()
	{
		/*cout << "\t _AddNewClientMenue here" << endl;*/
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _DeleteClientMenue()
	{
		//cout << "\t _DeleteClientMenue here" << endl;
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _UpdateClientMenue()
	{
		//cout << "\t _UpdateClientMenue here" << endl;
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _FindClientMenue()
	{
		//cout << "\t _FindClientMenue here" << endl;
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _TransactionsMenue()
	{
		//cout << "\t _TransactionsMenue here" << endl;
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	static void _ManageUsersMenue()
	{
		clsManageUserScreen::ShowManageUsersScreen();
		//cout << "\t _ManageUsersMenue here" << endl;
	}
	static void _LogoutScreen()
	{
		//cout << "\t _ShowEndScreen here" << endl;
		CurrentUser = clsUser::Find("");
		system("cls");
		cout << "\tPress Any Key to exit" << endl;
		system("pause>0");
	}

	static void _LoginRegisterMenue()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _CurrencyExchangeMenue()
	{
		clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMenue();
		//cout << "_CurrencyExchangeMenue here" << endl;
	}

	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOptions)
	{
		switch (MainMenueOptions)
		{
		case clsMainScreen::eListClients:
			system("cls");
			_ShowClientsListMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_AddNewClientMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_DeleteClientMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_UpdateClientMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_FindClientMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eShowTransactionsMenue:
			system("cls");
			_TransactionsMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			_ManageUsersMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eLoginRegister:
			system("cls");
			_LoginRegisterMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eCurrencyExchange:
			system("cls");
			_CurrencyExchangeMenue();
			_GoToBackToMainMenue();
			break;
		case clsMainScreen::eExit:
			system("cls");
			_LogoutScreen();
		//	_GoToBackToMainMenue();
			break;
		default:
			break;
		}
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\tMain Screen");
		cout << "\t\t\t\t=============================" << endl;
		cout << "\t\t\t\t  [1] Show Clients List."<< endl;
		cout << "\t\t\t\t  [2] Add New Client."<< endl;
		cout << "\t\t\t\t  [3] Delete Client."<< endl;
		cout << "\t\t\t\t  [4] Update Client Info."<< endl;
		cout << "\t\t\t\t  [5] Find Client."<< endl;
		cout << "\t\t\t\t  [6] Transactions."<< endl;
		cout << "\t\t\t\t  [7] Manage Users."<< endl;
		cout << "\t\t\t\t  [8] Login Resgisters."<< endl;
		cout << "\t\t\t\t  [9] Currency Exchange."<< endl;
		cout << "\t\t\t\t  [10] Logout."<< endl;
		cout << "\t\t\t\t=============================" << endl;
		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}


};

