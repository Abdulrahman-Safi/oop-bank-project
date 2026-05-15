#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"


class clsCurrencyCalculator:protected clsScreen
{
  
private:

	static float _ReadAmount()
	{
		float Amount = 0;
		cout << "\nEnter Amount to Exchange: ";

		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;



	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;

	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title="Currency Card:")
	{
		cout << "\n" << Title << "\n";
		cout << "\n_____________________________________\n";
		cout << "\nCountry     :" << Currency.Country();
		cout << "\nCode         :" << Currency.CurrencyCode();
		cout << "\nName         :" << Currency.CurrencyName();
		cout << "\nRate(1$) =   :" << Currency.Rate();
		cout << "\n_____________________________________\n";

	}

	static void _PrintClaculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert Form");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrrency(Amount, Currency2);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();

	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';


		while(Continue=='y'|| Continue=='Y')
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code:");
			float Amount = _ReadAmount();

			_PrintClaculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n";
			cin >> Continue;

		}

		

	}


};

