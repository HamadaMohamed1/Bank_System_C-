#pragma once 
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private:
	static void _PrintRecord(clsCurrency Record)
	{
        cout << "__________________________________" << endl;
        cout << "_________ Currency Card __________" << endl;
        cout << "__________________________________" << endl;
		cout << " Country       : " << Record.Country() << endl;
		cout << " Currency Code : " << Record.CurrencyCode() << endl;
		cout << " Rate (1$)     : " << Record.Rate() << endl;
        cout << "__________________________________" << endl;
	}
public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("   Find Currency Screen");
        
        cout << "\nFind by :[1] Code , [2] Country ? ";

        short choise = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter a number between 1 and 2");
        if (choise == 1) /*find by code*/
        {
            cout << "Enter the code" << endl;
            string currency_code = clsInputValidate::ReadString();

            currency_code = clsString::UpperAllString(currency_code);

            clsCurrency currency = clsCurrency::FindByCode(currency_code);
            if (!currency.IsEmpty())
            {
                _PrintRecord(currency);
            }
            else
            {
                cout << "Currency not exist" << endl;
            }
        }
        else/*find by country*/
        {
            cout << "Enter the country" << endl;
            string country_name = clsInputValidate::ReadString();

            country_name = clsString::UpperAllString(country_name);

            clsCurrency currency = clsCurrency::FindByCountry(country_name);
            if (!currency.IsEmpty())
            {
                _PrintRecord(currency);
            }
            else
            {
                cout << "Currency not exist" << endl;
            }
        }
    }
};

