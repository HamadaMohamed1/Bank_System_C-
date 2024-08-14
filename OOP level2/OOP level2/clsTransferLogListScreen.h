#pragma once
#include"clsScreen.h"
#include"iomanip"
#include"clsBankClient.h"
#include"vector"

class clsTransferLogListScreen : protected clsScreen
{
private:

	static void PrintRecord(clsBankClient::stTrnsferLogRecord Record)
	{
		cout << " | " << left << setw(20) << Record.date_time;
		cout << " | " << left << setw(20) << Record.source_account_number;
		cout << " | " << left << setw(15) << Record.destination_account_number;
		cout << " | " << left << setw(10) << Record.amount;
		cout << " | " << left << setw(10) << Record.source_balance;
		cout << " | " << left << setw(10) << Record.destination_balance;
		cout << " | " << left << setw(10) << Record.username << endl;
	}

public:

	static void ShowRegisterLogList()
	{
		vector <clsBankClient::stTrnsferLogRecord> TransferLogList = clsBankClient::GetTransfersLogList();

		_DrawScreenHeader("\Transfer Log List Screen", "\t(" + to_string(TransferLogList.size()) + ") Records");
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
		cout << " | " << left << setw(20) << "Date - Time";
		cout << " | " << left << setw(20) << "S. Acc. number";
		cout << " | " << left << setw(15) << "D. Acc. number";
		cout << " | " << left << setw(10) << "Amount";
		cout << " | " << left << setw(10) << "S. Balance";
		cout << " | " << left << setw(10) << "D. Balance";
		cout << " | " << left << setw(10) << "UserName" << endl;
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;

		if (TransferLogList.size() == 0)
		{
			cout << "\t\t\t\tThere are no Records" << endl;
		}
		else
		{
			for (clsBankClient::stTrnsferLogRecord& record : TransferLogList)
			{
				PrintRecord(record);
			}
		}
		cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
	}
};

