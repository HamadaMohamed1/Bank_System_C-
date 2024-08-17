#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsListCurenciesScreen : protected clsScreen
{
	static void PrintRecord(clsCurrency Record)
	{
		cout << " | " << left << setw(30) << Record.Country();
		cout << " | " << left << setw(15) << Record.CurrencyCode();
		cout << " | " << left << setw(40) << Record.CurrencyName();
		cout << " | " << left << setw(15) << Record.Rate() << endl;
	}

public:

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vect_currencies = clsCurrency::GetCurrenciesList();

		_DrawScreenHeader("Currencies List Screen", "\t(" + to_string(vect_currencies.size()) + ") Records");
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " | " << left << setw(30) << "Country Name";
		cout << " | " << left << setw(15) << "Currency Code";
		cout << " | " << left << setw(40) << "Currency Name";
		cout << " | " << left << setw(15) << "Currency Rate" << endl;
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;

		if (vect_currencies.size() == 0)
		{
			cout << "\t\t\t\tThere are no Records" << endl;
		}
		else
		{
			for (clsCurrency& record : vect_currencies)
			{
				PrintRecord(record);
			}
		}
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
	}
};

