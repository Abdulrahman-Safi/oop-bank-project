#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsCurrencyLiestScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculator.h"

class clsCurrencyScreen : protected clsScreen
{

private:

	enum enCurrencyMenueOption
	{
		elistCurrency = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4,
		eShowMainMenue = 5
	
	};

	static short _ReadCurrencyMenueOption()
	{   
		cout << setw(37) << left << "" << " Choose what do you want to do? [1 to 5]?  ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	   
	}

	static void _GoBacktoCurrencyMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrencyScreen();

	}

	static void _ShowListCurrencyScreen()
	{	
		/*cout << "\nList Currency Screen will be here \n";*/
		clsCurrencyLiestScreen::ShowCurrenciesListScreen();
	    
    } 

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "\nFind Currency Screen will be here \n";*/
		clsFindCurrency::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateCurrencyScreen()
	{
		/*cout << "\nUpdate Currency Screen will be here \n";*/
		clsUpdateCurrency::ShowUpdateCurrencyScreen();

	}

	static void _ShowCurrencyCalculatorScreen()
	{
	/*	cout << "\nCurrency Calculator Screen will be here \n";*/
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();

	}

	static void _ShowMainMenueScreen()
	{
		cout << "\Main Menue Screen will be here \n";

	}

	static void _PerfromMainMenueOption(enCurrencyMenueOption MainMenueOption)
	{
	  switch (MainMenueOption)
	  {

		case enCurrencyMenueOption::elistCurrency:
		{
			system("cls");
			_ShowListCurrencyScreen();
			_GoBacktoCurrencyMenue();
			break;
		}

		case enCurrencyMenueOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBacktoCurrencyMenue();
			break;
		}

		case enCurrencyMenueOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBacktoCurrencyMenue();
			break;
		}
	
		case enCurrencyMenueOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBacktoCurrencyMenue();
			break;
		}

		case enCurrencyMenueOption::eShowMainMenue:
		{

		}

	  }

	}

public:

	static void ShowCurrencyScreen()
	{

		system("cls");

		_DrawScreenHeader("Currency Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currenies. \n ";
		cout << setw(37) << left << "" << "\t[2] Find Currency. \n ";
		cout << setw(37) << left << "" << "\t[3] Update Rate. \n ";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator. \n ";
		cout << setw(37) << left << "" << "\t[5] Main Menue. \n ";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enCurrencyMenueOption)_ReadCurrencyMenueOption());



	}


};

