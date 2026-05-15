#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreeen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class TransactionScreen :protected clsScreen
{
private:

	enum enTransactionMenueOption
	{
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4,
		eRigsterTransfer=5, eShowMainMenue =6

	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left<<"" << " Choose what do you want to do? [1 to 6]?  ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowTansactionsMenue();
	}

	static void _ShowDepositScreen()
	{
		/*cout << "\nDeposit Screen Will be here \n";*/
		clsDepositScreeen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		/*cout << "\nWithdraw Screen Will be here \n";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		/*cout << "\n Balances Screen Will be here \n";*/
		clsTotalBalancesScreen::ShowTotalBalance();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen Will be here \n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowRigesterLogScreen()
	{
		/*cout << "\nRigester Transfer Screen Will be here \n";*/
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _ShowMainMenueScreen()
	{
		cout << "\nMain Menue Screen Will be here \n";
	}

	static void _PerfromMainMenueOption(enTransactionMenueOption MainMenueOption)
	{
       switch (MainMenueOption)
	   {

		  case enTransactionMenueOption::eDeposit :
		  {
			  system("cls");
			  _ShowDepositScreen();
			  _GoBackToTransactionMenue();
			  break;
		  }
		  case enTransactionMenueOption::eWithdraw:
		  {
			  system("cls");
			  _ShowWithdrawScreen();
			  _GoBackToTransactionMenue();
			  break;
		  }
		  case enTransactionMenueOption::eShowTotalBalance:
		  {
			  system("cls");
			  _ShowTotalBalanceScreen();
			  _GoBackToTransactionMenue();
			  break;
		  }
		  case enTransactionMenueOption::eTransfer:
			  system("cls");
			  _ShowTransferScreen();
			  _GoBackToTransactionMenue();
			  break;

		  case enTransactionMenueOption::eRigsterTransfer:
			  system("cls");
			  _ShowRigesterLogScreen();
			  _GoBackToTransactionMenue();
			  break;

		  case enTransactionMenueOption::eShowMainMenue:
		  {
			  
		  }

	   }



	}

public:

	static void ShowTansactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Transaction Screen ");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Transaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit. \n ";
		cout << setw(37) << left << "" << "\t[2] Withdraw. \n ";
		cout << setw(37) << left << "" << "\t[3] Total Balances. \n ";
		cout << setw(37) << left << "" << "\t[4] Transfer. \n ";
		cout << setw(37) << left << "" << "\t[5] Transfer Log. \n ";
		cout << setw(37) << left << "" << "\t[6] Main Menue. \n ";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enTransactionMenueOption)_ReadTransactionsMenueOption());
	}

};

