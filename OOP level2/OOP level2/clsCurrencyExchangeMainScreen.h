#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListCurenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptions{enListCurrencies = 1 ,enFindCurrency = 2 , enUpdateRate = 3 ,
	enCurrencyCalculator = 4 , enMainMenue = 5};

	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	
	static void _ListCurrencies()
	{
		clsListCurenciesScreen::ShowCurrenciesList();
		//cout << "_ListCurrencies here" << endl;;
	}
	
	static void _ShowCalculator()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
		//cout << "_ListCalculator here" << endl;;
	}

	static void _FindCurrency()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
		//cout << "_FindCurrency here" << endl;;
	}

	static void _UpdateCurrency()
	{
		//cout << "_UpdateCurrency here" << endl;
		clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeMenue();
	}

	static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
	{
		switch (CurrencyExchangeMenueOption)
		{
		case enCurrencyExchangeMenueOptions::enListCurrencies:
			system("cls");
			_ListCurrencies();
			_GoBackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptions::enFindCurrency:
			system("cls");
			_FindCurrency();
			_GoBackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptions::enCurrencyCalculator:
			system("cls");
			_ShowCalculator();
			_GoBackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptions::enUpdateRate:
			system("cls");
			_UpdateCurrency();
			_GoBackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptions::enMainMenue:

			break;
		}
	}

public:

	static void ShowCurrencyExchangeMenue()
	{
		//if (!CheckAccessRights(clsUser::enPermessions::pTransactions))
		//{
		//	return; /*User Don't have permissions*/
		//}

		system("cls");
		_DrawScreenHeader("Currency Exchange Screen");
		 
		cout << "\t\t\t\t    ==================================" << endl;
		cout << "\t\t\t\t      Currency Exchange Menue" << endl;
		cout << "\t\t\t\t    ==================================" << endl;
		cout << "\t\t\t\t     [1] List Currencies.\n";
		cout << "\t\t\t\t     [2] Find Currency.\n";
		cout << "\t\t\t\t     [3] Update Rate.\n";
		cout << "\t\t\t\t     [4] Currency Calculator.\n";
		cout << "\t\t\t\t     [5] Main Menue.\n";
		cout << "\t\t\t\t    ================================" << endl;

		_PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
	}

};

