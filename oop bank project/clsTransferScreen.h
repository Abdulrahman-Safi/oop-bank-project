#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferScreen:protected clsScreen
{

private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n Client Card:";
		cout << "\n______________________\n";
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nAcc. Number :" << Client.AccountNumber();
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n______________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\n Please Enter Account Number to Transfer From : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found , choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(DestinationClient);

		float Amount = _ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "Transfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}

		}

		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

	}

};

