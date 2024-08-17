#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen : protected clsScreen
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

    static float _Currency_Calculator(clsCurrency currency1 , clsCurrency currency2 , float amount)
    {
        float result = 0;

        float currency1_rate = currency1.Rate();

        float currency2_rate = currency2.Rate();

        result = amount * (currency2_rate / currency1_rate);

        return result;
    }

    static clsCurrency _GetCurrency()
    {
        cout << "\nEnter the Currency code" << endl;
        string currency_code = clsInputValidate::ReadString();

        currency_code = clsString::UpperAllString(currency_code);

        clsCurrency currency = clsCurrency::FindByCode(currency_code);

        return currency;
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char choice;
        do
        {
            system("cls");
            _DrawScreenHeader("   Currency Calculator Screen");

            cout << "\nCurrency 1 " << endl;
            clsCurrency currency1 = _GetCurrency();
            if (currency1.IsEmpty())
            {
                cout << "Currency not exist" << endl;
                return;
            }
            _PrintRecord(currency1);

            cout << "\nCurrency 2 " << endl;
            clsCurrency currency2 = _GetCurrency();
            if (currency2.IsEmpty())
            {
                cout << "Currency not exist" << endl;
                return;
            }
            _PrintRecord(currency2);

            cout << "\nEnter Amount to Exchange " << endl;
            float amount = clsInputValidate::ReadFloatNumber();

            float result = _Currency_Calculator(currency1, currency2, amount);

            cout << amount << " " << currency1.CurrencyCode() << " = " << result << " " << currency2.CurrencyCode() << endl;
        
            cout << "Do you want to perform another calculation ? y/n" << endl;
            cin >> choice;
        } while(choice == 'y' || choice == 'Y');
    }
};

