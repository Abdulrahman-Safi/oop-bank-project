#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

	static bool _Login()
	{

		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName, Password;

		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvalid UserName/Password!";
				cout << "\nYou have " << (3-FaildLoginCount) << " Trials to login\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\n\nYou are Locked after 3 faild trials \n\n";
				return false;
			}

			cout << "Enter UserName? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}



public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Login Screen ");
		return _Login();

	}



};

