#pragma once

#include<iostream>
#include <string>
using namespace std;

class clsUtil
{
public:
	enum enCharType
	{
		SmallLetter = 0,
		CapitalLetter ,
		Digit ,
		MixChar ,
		SpecialCharacter
	};

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once    
		srand((unsigned)time(NULL));
	}
	
	static int RandomNumberInRange(int from, int to)
	{
		return rand() % (to - from) + from;
	}

	static char RandomCharacter(enCharType Type)
	{
		switch (Type)
		{
		case clsUtil::SmallLetter:
			return char(RandomNumberInRange(97, 122));
			break;
		case clsUtil::CapitalLetter:
			return char(RandomNumberInRange(65, 90));
			break;
		case clsUtil::Digit:
			return char(RandomNumberInRange(48, 57));
			break;
		case clsUtil::MixChar:
			return char(RandomNumberInRange(33, 122));
			break;
		case clsUtil::SpecialCharacter:
			return char(RandomNumberInRange(33, 47));
			break;
		}
	}


	static string RandomWord(enCharType CharType, short Length)
	{
		string word;

		for (short i = 1 ; i <= Length ; i++)
		{
			word += RandomCharacter(CharType);
		}
		return word;
	}

	static string RandomKey(clsUtil::enCharType Type)
	 {
		string key;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				key += RandomCharacter(Type);
			}
			if (i == 3)
				continue;
			key += '-';
		}
		return key;
	 }

	static void RandomKeys(enCharType CharType, short Length)
	{
		string key;
		for (short i = 0; i < Length ; i++)
		{
			cout << "Key [" << i+1 << "]:" << RandomKey(CharType) << endl;;
		}
	}

	static void Swap(int &num1, int &num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(float& num1, float& num2)
	{
		float temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(double &num1, double& num2)
	{
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(string& str1, string& str2)
	{
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}

	static void ShuffleArray(int arr[100] , short length)
	{
		for (int i = 0; i < length; i++)
		{
			Swap(arr[RandomNumberInRange(1, length) - 1], arr[RandomNumberInRange(1, length) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], short length)
	{
		for (int i = 0; i < length; i++)
		{
			Swap(arr[RandomNumberInRange(1, length) - 1], arr[RandomNumberInRange(1, length) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int length, int from, int to)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = RandomNumberInRange(from, to);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int length , short WordLength,clsUtil::enCharType CharType)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = RandomWord(CharType, WordLength);
		}
	}

	static string Tap(short NumberOfTaps)
	{
		string taps = "";
		for (short i = 0; i < NumberOfTaps; i++)
		{
			taps += "\t";
		}
		return taps;
	}

	static string EncryptText(string text, short key=2)
	{
		for (short i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] + key);
		}
		return text;
	}
	
	static string DecryptText(string text, short key=2)
	{
		for (short i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] - key);
		}
		return text;
	}

	static string NumberToText(int number)
	{
		if (number == 0)
		{
			return "";
		}

		if (number >= 1 && number <= 19)
		{
			string arr[] = { "","One ","Two ","Three ","Four ","Five ","Six ","Seven ",
			"Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ",
			"Fifteen ","Sixteen ","Seventeen ","Eighteen ","Ninteen " };
			return arr[number];
		}

		if (number >= 20 && number <= 99)
		{
			string arr[] = { "","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ",
			"Seventy ","Eighty ","Nintey " };
			return arr[number / 10] + NumberToText(number % 10);
		}

		if (number >= 100 && number <= 199)
		{
			return "One Handred " + NumberToText(number % 100);
		}

		if (number >= 200 && number <= 999)
		{
			return NumberToText(number / 100) + "Handreds " + NumberToText(number % 100);
		}

		if (number >= 1000 && number <= 1999)
		{
			return "One Thounsand " + NumberToText(number % 1000);
		}

		if (number >= 2000 && number <= 999999)
		{
			return NumberToText(number / 1000) + "Thounsands " + NumberToText(number % 1000);
		}

		if (number >= 1000000 && number <= 1999999)
		{
			return "One Million " + NumberToText(number % 1000000);
		}

		if (number >= 2000000 && number <= 999999999)
		{
			return NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
		}

		if (number >= 1000000000 && number <= 1999999999)
		{
			return"One Billion " + NumberToText(number % 1000000000);
		}
		else
		{
			return   NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
		}
	}


};

