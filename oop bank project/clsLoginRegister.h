#pragma once
#include <iostream>
#include <fstream>
#include "clsUser.h"
#include "iomanip"
#include "clsScreen.h"

class clsLoginRegister:protected clsScreen
{
private:

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;

    }


public:
      static void ShowLoginRegister()
      {
          if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
          {
              return;
          }

          vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

          string Title = "\t  Login Register Screen";
          string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") User(s).";

          _DrawScreenHeader(Title, SubTitle);

          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;


          cout << setw(8) << left << "" << "| " << left << setw(30) << "Date";
          cout << "| " << left << setw(20) << "UserName";
          cout << "| " << left << setw(20) << "Password";
          cout << "| " << left << setw(10) << "Permissions";


          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;

          if (vLoginRegisterRecord.size() == 0)
              cout << "\t\t\t\tNo Users Available In the System!";

          else

              for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
              {

                  _PrintLoginRegisterRecordLine(Record);
                  cout << endl;
              }

          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;
      }
      
};

