#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"


using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

   

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkForDelete() == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> vClients;
        vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(vClients);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareLoginTransfer(float Amount, clsBankClient Destination,string UserName, string Seperator = "#//#")
    {
        string LineRecord = "";

        LineRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LineRecord += AccountNumber() + Seperator;
        LineRecord += Destination.AccountNumber() + Seperator;
        LineRecord += to_string(Amount) + Seperator;
        LineRecord += to_string(AccountBalance) + Seperator;
        LineRecord += to_string(Destination.AccountBalance) + Seperator;
        LineRecord += UserName;

        return LineRecord;
    }

    struct stTransferLog;
    static stTransferLog _ConvertTransferlogToRecord(string Line, string Seperator = "#//#")
    {
        stTransferLog TransferLog;

        vector <string> vTransferLog;
        vTransferLog = clsString::Split(Line, Seperator);

        TransferLog.DateTime = vTransferLog[0];
        TransferLog.SourceClient = vTransferLog[1];
        TransferLog.DestinationClient = vTransferLog[2];
        TransferLog.Amount = stof(vTransferLog[3]);
        TransferLog.SourceBalance = stof(vTransferLog[4]);
        TransferLog.DestinationBalance = stof(vTransferLog[5]);
        TransferLog.UserName = vTransferLog[6];

        return TransferLog;
    }

    void _RegisterTransferLog(float Amount, clsBankClient Desetination,string UserName)
    {
        string stDataLine = _PrepareLoginTransfer(Amount, Desetination, UserName);

        fstream Myfile;

        Myfile.open("TransferLog.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {

            Myfile << stDataLine << endl;
            Myfile.close();
        }

    }

public:

    struct stTransferLog
    {
        string DateTime;
        string SourceClient;
        string DestinationClient;
        float Amount;
        float SourceBalance;
        float DestinationBalance;
        string UserName;
    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    //No UI Related code inside object.
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

        }

        }
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {

        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);


    }

    bool Delete()
    {
        vector<clsBankClient>vClient;
        vClient = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClient)
        {

            if (C.AccountNumber() == _AccountNumber)
            {

                C._MarkForDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(vClient);
        *this = _GetEmptyClientObject();
        return true;

    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();


    }

    static double GetTotalBalance()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        double TotalBalance = 0;

        for (clsBankClient Client : vClients)
        {
            TotalBalance += Client.AccountBalance;
        }
        return TotalBalance;
    }

    void Deposit(double Amount)
    {
        AccountBalance += Amount;
        Save();
    }
      
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
      
    }

     bool Transfer(float Amount,clsBankClient & DestinationClient,string UserName)
     { 
         if (Amount > AccountBalance)
         {
             return false;
         }
         
         Withdraw(Amount);
         DestinationClient.Deposit(Amount);
         _RegisterTransferLog(Amount, DestinationClient, UserName);
         return true;
     }

     static vector<stTransferLog>GetTransferLogList()
     {
         vector <stTransferLog>vTransferRegisterLog;

         fstream Myfile;
         Myfile.open("TransferLog.txt", ios::in);

         if (Myfile.is_open())
         {
             string Line;
             
             stTransferLog TrnsferLog;
             while (getline(Myfile, Line))
             {
                 TrnsferLog = _ConvertTransferlogToRecord(Line);
                 vTransferRegisterLog.push_back(TrnsferLog);
             }


             Myfile.close();
         }
         return vTransferRegisterLog;
     }

   

};

