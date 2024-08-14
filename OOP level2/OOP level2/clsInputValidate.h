#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number")
	{
		int num;
		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage<<endl;
		}
		return num;
	}
	static short ReadShortNumber(string ErrorMessage = "Invalid Number")
	{
		short num;
		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return num;
	}
	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number")
	{
		double num;
		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return num;
	}

	static int ReadIntNumberBetween(int From , int To , string ErrorMessage)
	{
		int num = ReadIntNumber("Invalid Number");
		while (!IsNumberBetween(num, From, To))
		{
			cout << ErrorMessage << endl;
			num = ReadIntNumber("Invalid Number");
		}
		return num;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage)
	{
		short num = ReadShortNumber(ErrorMessage);
		while (!IsNumberBetween(num, From, To))
		{
			cout << ErrorMessage << endl;
			num = ReadShortNumber(ErrorMessage);
		}
		return num;
	}
	static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage)
	{
		double num = ReadDoubleNumber("Invalid Number");
		while (!IsNumberBetween(num, From, To))
		{
			cout << ErrorMessage << endl;
			num = ReadDoubleNumber("Invalid Number");
		}
		return num;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number")
	{
		float num;
		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return num;
	}
	static string ReadString()
	{
		string str = "";
		getline(cin >> ws, str);
		return str;
	}

};

