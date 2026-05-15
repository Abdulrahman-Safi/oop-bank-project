#pragma once
#include <iostream>
#include <fstream>
#include "clsBankClient.h"
#include "iomanip"
#include "clsScreen.h"


class clsTransferLogScreen:protected clsScreen
{

    private:
    static void _PrintLoginRegisterRecordLine(clsBankClient::stTransferLog TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceClient;
        cout << "| " << setw(8) << left << TransferLog.DestinationClient;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.SourceBalance;
        cout << "| " << setw(10) << left << TransferLog.DestinationBalance;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }


  public:
      static void ShowTransferLogScreen()
      {
          vector<clsBankClient::stTransferLog>vTransferLog = clsBankClient::GetTransferLogList();


          string Title = "\t  Transfer Log Screen";
          string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") User(s).";

          _DrawScreenHeader(Title, SubTitle);

          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;

          cout << setw(8) << left << "" << "| " << left << setw(23) << "Date";
          cout << "| " << left << setw(8) << "s.Acct";
          cout << "| " << left << setw(8) << "d.Acct";
          cout << "| " << left << setw(8) << "Amount";
          cout << "| " << left << setw(10) << "s.Balance";
          cout << "| " << left << setw(10) << "d.Balance";
          cout << "| " << left << setw(8) << "User";


          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;

          if (vTransferLog.size() == 0)
              cout << "\t\t\t\tNo Transfer Available In the System!";

          else
          
              for (clsBankClient::stTransferLog Record : vTransferLog)
              {
                  _PrintLoginRegisterRecordLine(Record);
                  cout << endl;
              }


          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
          cout << "______________________________________________\n" << endl;
      }



};

