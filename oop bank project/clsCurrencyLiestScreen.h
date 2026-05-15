#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include <iostream>

class clsCurrencyLiestScreen :protected clsScreen
{
private:

	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << left << setw(6) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();


	}
    
public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();
		string Title = "Currencies List Screen";
		string SubTitle = "\t   (" + to_string(vCurrency.size()) + ") Client(s). ";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(6) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vCurrency.size()==0)
		{
			cout << "\t\t\t\tNo Currency Found In the System! ";

		}
		else
		{
			for (clsCurrency Currency : vCurrency)
			{
				PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		    
		}


	}


};

