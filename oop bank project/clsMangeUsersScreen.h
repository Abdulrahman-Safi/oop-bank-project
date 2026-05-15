#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpadteUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsMangeUsersScreen:protected clsScreen
{
private :

	enum enMangeUsersMenueOption {
		eListUsers = 1, eAddNewUsers = 2, eDeletUsers = 3 ,
		eUpdateUsers = 4,eFindUsers = 5,eMainMenue = 6
	};
	static short _ReadMangeUsersMenueOption()
	{
		cout << setw(37) << left << "" << " Choose what do you want to do? [1 to 6]?  ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 4? ");
		return Choice;
	}
	static void _GoBackToMangeUsersMenueOption()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMangeUsersMenue();
	}
	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screeen will be here ......";
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUsersScreen()
	{
	/*	cout << "\nAdd New Users Screeen will be here ......";*/
		clsAddNewUserScreen::ShowAddUserScreen();
	}
	static void _ShowDeleteUsersScreen()
	{
		/*cout << "\nDelete Users Screeen will be here ......";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUsersScreen()
	{
		//cout << "\nUpdate Users Screeen will be here ......";
		clsUpadteUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUsersScreen()
	{
		/*cout << "\nFind Users Screeen will be here ......";*/
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _PerformMangeUsersMenueOption(enMangeUsersMenueOption MainMenueOption)
	{
	   switch (MainMenueOption)
	   {
	     case enMangeUsersMenueOption::eListUsers:
	      {
			 system("cls");
			 _ShowListUsersScreen();
			 _GoBackToMangeUsersMenueOption();
			 break;
		  }
		 case enMangeUsersMenueOption::eAddNewUsers:
		  {

			 system("cls");
			 _ShowAddNewUsersScreen();
			 _GoBackToMangeUsersMenueOption();
			 break;

		  }
		 case enMangeUsersMenueOption::eDeletUsers:
		  {
			 system("cls");
			 _ShowDeleteUsersScreen();
			 _GoBackToMangeUsersMenueOption();
			 break;
		  }
		 case enMangeUsersMenueOption::eUpdateUsers:
		  {
			 system("cls");
			 _ShowUpdateUsersScreen();
			 _GoBackToMangeUsersMenueOption();
			 break;
		  }
		 case enMangeUsersMenueOption::eFindUsers:
		  {
			 system("cls");
			 _ShowFindUsersScreen();
			 _GoBackToMangeUsersMenueOption();
			 break;
		  }
		 case enMangeUsersMenueOption::eMainMenue:
		  {
			
		  }


       }
      

	}



public:

	static void ShowMangeUsersMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformMangeUsersMenueOption((enMangeUsersMenueOption)_ReadMangeUsersMenueOption());

	}

};


