#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"



class clsDepositScreeen :public clsScreen
{

private :

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

  public:
	  static void ShowDepositScreen()
	  {
		  _DrawScreenHeader("\t  Deposit Screen");


		  string AccountNumber = _ReadAccountNumber();

		  while (!clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << "\n Client with [" << AccountNumber << "] dose not Found\n";
			  AccountNumber = _ReadAccountNumber();
		  }
		  clsBankClient Client = clsBankClient::Find(AccountNumber);
		  _PrintClient(Client);

		  double Amount = 0;
		  cout << "\nPlease enter deposit amount? ";
		  Amount = clsInputValidate::ReadDblNumber();


		  cout << "Are you sure you want to perform this transaction?  ";
		  char Answer = 'n';
		  cin >> Answer;

		  if (Answer == 'y' || Answer == 'Y')
		  {
			  Client.Deposit(Amount);
			  cout << "\n Amount Deposit Successfully.\n";
			  cout << "\n New Balance Is : " << Client.AccountBalance;
		  }
		  else
		  {
			  cout << "\nOperation was cancelled.\n";
		  }

      }
	

};

