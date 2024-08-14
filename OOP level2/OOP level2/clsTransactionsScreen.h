#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDipositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogListScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowTransferScreen =4 , 
		eShowTransferLogListScreen =5, eShowMainMenue = 6
	};

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	
	static void _ShowDepositScreen()
	{
		//cout << "\n Deposit Screen will be here.\n";
		clsDipositScreen::ShowDipositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\n Withdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n Balances Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferLogListScreen()
	{
		clsTransferLogListScreen::ShowRegisterLogList();
	}
	
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}
	
	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTransferScreen:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTransferLogListScreen:
		{
			system("cls");
			_ShowTransferLogListScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}


public:


	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pTransactions))
		{
			return; /*User Don't have permissions*/
		}

		system("cls");
		_DrawScreenHeader("Transactions Screen");

		cout << "\t\t\t\t=============================" << endl;
		cout << "\t\t\t\t\tTransactions Menue" << endl;
		cout << "\t\t\t\t=============================" << endl;
		cout << "\t\t\t\t  [1] Deposit.\n";
		cout << "\t\t\t\t  [2] Withdraw.\n";
		cout << "\t\t\t\t  [3] Total Balances.\n";
		cout << "\t\t\t\t  [4] Transfer Screen.\n";
		cout << "\t\t\t\t  [5] Transfer Log List Screen.\n";
		cout << "\t\t\t\t  [6] Main Menue.\n";
		cout << "\t\t\t\t=============================" << endl;

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}

};