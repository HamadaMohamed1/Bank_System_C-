#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsUpdateCurrencyRate : protected clsScreen
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
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("   Update Currency Rate Screen");
     
        cout << "Enter the currency code" << endl;

        string currency_code = clsInputValidate::ReadString();

        currency_code = clsString::UpperAllString(currency_code);

        clsCurrency currency = clsCurrency::FindByCode(currency_code);
        if (!currency.IsEmpty())
        {
            _PrintRecord(currency);
            
            cout << "Enter new Rate" << endl;
            float new_rate = clsInputValidate::ReadFloatNumber();

            currency.UpdateRate(new_rate);

            _PrintRecord(currency);
        }
        else
        {
            cout << "Currency not exist" << endl;
        }

    }

};

