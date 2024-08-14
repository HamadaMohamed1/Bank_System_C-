#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include <vector>
#include <fstream>
class clsBankClient : public clsPerson
{
private:
	struct stTrnsferLogRecord;
	enum enMode{EmptyMode = 0 , UpdatedMode , AddNewMode};
	enMode _mode;
	string _account_number;
	string _pin_code;
	float  _account_balance;
	bool   _marked_to_delete = false;

	static clsBankClient _convert_line_to_client_object(string line, string separator = "#//#")
	{
		vector <string> vect;
		vect = clsString::Split(line, separator);
		return clsBankClient(enMode::UpdatedMode,vect[0],vect[1],vect[2],vect[3],vect[4],vect[5],stod(vect[6]));
	}

	static string _convert_client_object_to_line(clsBankClient client , string separator = "#//#")
	{
		string line = "";
		line += client.FirstName + separator;
		line += client.LastName + separator;
		line += client.Email + separator;
		line += client.Phone + separator;
		line += client.GetAccountNumber() + separator;
		line += client.PinCode + separator;
		line += to_string(client.AccountBalance);
		return line;
	}

	static vector<clsBankClient> _load_clients_from_file()
	{
		vector<clsBankClient> vect;
		fstream myFile;
		myFile.open("Clients.txt", ios::in);

		if(myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				vect.push_back(_convert_line_to_client_object(line));
			}
			myFile.close();
		}
		return vect;
	}

	static void _save_clients_to_file(vector<clsBankClient> vectClients)
	{
		fstream myFile;
		myFile.open("Clients.txt", ios::out);
		if (myFile.is_open())
		{
			for (clsBankClient &c : vectClients)
			{
				if (c._marked_to_delete == false)
				{
					string line = _convert_client_object_to_line(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}

	static clsBankClient _get_empty_client()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _update()
	{
		vector<clsBankClient> vectClients;
		vectClients = _load_clients_from_file();
		for (clsBankClient& c : vectClients)
		{
			if (c.GetAccountNumber() == _account_number)
			{
				c = *this;
				break;
			}
		}
		_save_clients_to_file(vectClients);
	}

	void _add_new()
	{
		_add_data_line_to_file(_convert_client_object_to_line(*this));
	}
	
	void _add_data_line_to_file(string dataLine)
	{
		fstream myFile;
		myFile.open("Clients.txt", ios::out | ios::app);
		if (myFile.is_open())
		{
			myFile << dataLine << endl;
			myFile.close();
		}
	}
	
	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += _account_number + Seperator;
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine		= clsString::Split(Line, Seperator);
		TrnsferLogRecord.date_time					= vTrnsferLogRecordLine[0];
		TrnsferLogRecord.source_account_number		= vTrnsferLogRecordLine[1];
		TrnsferLogRecord.destination_account_number	= vTrnsferLogRecordLine[2];
		TrnsferLogRecord.amount						= stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.source_balance				= stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destination_balance		= stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.username					= vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	



public:
	struct stTrnsferLogRecord
	{
		string date_time;
		string source_account_number;
		string destination_account_number;
		float  amount;
		float  source_balance;
		float  destination_balance;
		string username;
	};
	clsBankClient(enMode Mode ,string FirstName, string LastName, string Email, 
					string Phone , string AccountNumber , string PinCode , float AccountBalance)
		:clsPerson(FirstName , LastName , Email , Phone)
	{
		_mode = Mode;
		_account_number = AccountNumber;
		_account_balance = AccountBalance;
		_pin_code = PinCode;
	}

	bool IsEmpty()
	{
		return (_mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _account_number;
	}

	void SetPinCode(string PinCode)
	{
		_pin_code = PinCode;
	}
	string GetPinCode()
	{
		return _pin_code;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_account_balance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _account_balance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	bool GetMarkedForDeleted()
	{
		return _marked_to_delete;
	}
/*
	void Print()
	{
		cout << "******************************************************************" << endl;
		cout << "                          Client Card                             " << endl;
		cout << "******************************************************************" << endl;
		cout << "Name           : " << GetFullName()	  << endl;
		cout << "Email          : " << GetEmail()		  << endl;
		cout << "Phone          : " << GetPhone()		  << endl;
		cout << "Account Number : " << GetAccountNumber() << endl;
		cout << "Pin Code       : " << GetPinCode()		  << endl;
		cout << "Balance        : " << GetAccountBalance()<< endl;
		cout << "******************************************************************\n" << endl ;
	}
*/
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convert_line_to_client_object(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _get_empty_client();
	}
	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convert_line_to_client_object(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _get_empty_client();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient client = clsBankClient::Find(AccountNumber);
		return (!client.IsEmpty());
	}

	enum enSaveResults { saveFaildEmptyObject = 0, saveSucceeded , saveFaildAccountNumberExist};

	enSaveResults Save()
	{
		switch (_mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::saveFaildEmptyObject;
			break;

		case clsBankClient::UpdatedMode:
			_update();
			return enSaveResults::saveSucceeded;
			break;

		case clsBankClient::AddNewMode:

			if (IsClientExist(_account_number))
			{
				return enSaveResults::saveFaildAccountNumberExist;
			}
			else
			{
				_add_new();
				_mode = clsBankClient::UpdatedMode;
				return enSaveResults::saveSucceeded;
			}
				break;

		default:
			break;
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vect;
		vect = _load_clients_from_file();

		for (clsBankClient& c : vect)
		{
			if (c.GetAccountNumber() == _account_number)
			{
				c._marked_to_delete = true;
				break;
			}
		}
		_save_clients_to_file(vect);
		*this = _get_empty_client();
		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _load_clients_from_file();
	}

	static double GetTotalBalances()
	{
		double total_balances = 0;
		vector<clsBankClient> vect;
		vect = _load_clients_from_file();
		for (clsBankClient& c : vect)
		{
			total_balances += c.GetAccountBalance();
		}
		return total_balances;
	}

	void Diposit(double amount)
	{
		_account_balance += amount;
		Save();
	}
	bool Withdraw(double amount)
	{
		if (amount < _account_balance)
		{
			_account_balance -= amount;
			Save();
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Diposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}

	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}
};

