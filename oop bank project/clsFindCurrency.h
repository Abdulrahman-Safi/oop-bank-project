#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindCurrency :protected clsScreen
{

private:

	static short _ReadOption()
	{
		short Option;
		Option = clsInputValidate::ReadIntNumberBetween(1, 2, "Enter [1] or [2]");

		return Option;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "\n_____________________________________\n";
		cout << "\nCountrry     :" << Currency.Country();
		cout << "\nCode         :" << Currency.CurrencyCode();
		cout << "\nName         :" << Currency.CurrencyName();
		cout << "\nRate         :" << Currency.Rate();
		cout << "\n_____________________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "\nCurrency Not Found :-(\n";
		}
		else
		{
			cout << "\nCurrency  Found :-)\n";

			_PrintCurrencyCard(Currency);
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "Find By: [1] Code or  [2]Country ? ";
		short Answer = _ReadOption();

		if (Answer == 1)
		{

			string CurrencyCode;
			cout << "\n\nPleease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\n\nPleease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency);
			

		}


	}


};

