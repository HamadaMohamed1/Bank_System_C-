#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"iomanip"
#include"clsUser.h"

class clsClientListScreen :protected clsScreen
{
private:
	static void PrintClient(clsBankClient client)
	{
		
		cout << " | " << left << setw(15) << client.GetAccountNumber();
		cout << " | " << left << setw(20) << client.GetFullName();
		cout << " | " << left << setw(15) << client.Phone;
		cout << " | " << left << setw(18) << client.Email;
		cout << " | " << left << setw(15) << client.PinCode;
		cout << " | " << left << setw(15) << client.AccountBalance << endl;
	}
public:
	static void ShowCLientsList()
	{
		if (!CheckAccessRights(clsUser::enPermessions::pListClients))
		{
			return; /*User Don't have permissions*/
		}
		vector <clsBankClient> ClientsList = clsBankClient::GetClientsList();
		_DrawScreenHeader("\tClient List Screen", "\t(" + to_string(ClientsList.size()) + ") Clients");
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;
		cout << " | " << left << setw(15) << "Account Number";
		cout << " | " << left << setw(20) << "Client Name";
		cout << " | " << left << setw(15) << "Phone";
		cout << " | " << left << setw(18) << "Email";
		cout << " | " << left << setw(15) << "Pin Code";
		cout << " | " << left << setw(15) << "Balance" << endl;
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;

		if (ClientsList.size() == 0)
		{
			cout << "\t\t\t\tThere are no clients" << endl;
		}
		else
		{
			for (clsBankClient& client : ClientsList)
			{
				PrintClient(client);
			}
		}
		cout << " ------------------------------------------------------------------------------------------------------------" << endl;
	}
};

