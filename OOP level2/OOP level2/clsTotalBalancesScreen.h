#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:
  
public:
    static void ShowTotalBalancesScreen()
    {
        _DrawScreenHeader("   Total Balances Screen");
            vector <clsBankClient> ClientsList = clsBankClient::GetClientsList();
        
            cout << "\t\t\t\t\t Client List (" << ClientsList.size() << ") Clients" << endl;
            cout << "\t\t\t\t-------------------------------------------------" << endl;
            cout << "\t\t\t\t| " << left << setw(15) << "Account Number";
            cout << "| " << left << setw(20) << "Client Name";
            cout << "| " << left << setw(15) << "Balance" << endl;
            cout << "\t\t\t\t-------------------------------------------------" << endl;
        
            if (ClientsList.size() == 0)
            {
                cout << "\t\tThere are no clients" << endl;
            }
            else
            {
                for (clsBankClient& client : ClientsList)
                {
                    cout << "\t\t\t\t| " << left << setw(15) << client.GetAccountNumber();
                    cout << "| " << left << setw(20) << client.GetFullName();
                    cout << "| " << left << setw(15) << client.AccountBalance << endl;
                }
            }
            cout << "\t\t\t\t-------------------------------------------------" << endl;
            cout << "\t\t\t\tTotal Balances : " << clsBankClient::GetTotalBalances() << endl;
            cout << "\t\t\t\t" << clsUtil::NumberToText(clsBankClient::GetTotalBalances()) << endl;
        
    }
};

