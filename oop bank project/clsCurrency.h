#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsString.h"
#include <fstream>


class clsCurrency
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string>vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Seperator;
		CurrencyRecord += Currency.CurrencyCode() + Seperator;
		CurrencyRecord += Currency.CurrencyName() + Seperator;
		CurrencyRecord += to_string(Currency.Rate());

		return CurrencyRecord;
	}

	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector<clsCurrency>vCurrency;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrency.push_back(Currency);

			}

			MyFile.close();
		}


		return vCurrency;
	}

	static  void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Dataline;

			for (const clsCurrency& C : vCurrencys)
			{
				Dataline = _ConverCurrencyObjectToLine(C);
				MyFile << Dataline << endl;

			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsCurrency>vCurrency;
		vCurrency = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(vCurrency);


	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();

	}

	float Rate()
	{
		return _Rate;
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencysDataFromFile();

	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();
		}
		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrrency(float Amount,clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());

	}


};

