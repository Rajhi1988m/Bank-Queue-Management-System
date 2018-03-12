//
//  Account.cpp
//  Bank_Queues_System
//
//  Created by Mohammed | UERNAME on 4/15/17.
//  Copyright © 2017 Mohammed | UERNAME . All rights reserved.
//

/*****************************************************************/
/*                   HEADER FILE USED IN PROJECT                 */
/*****************************************************************/

#include "User.hpp"     /* Declares the User class */
#include "Account.hpp"  /* Declares the Account class */

#include<stdio.h>   /* The stdio.h stands for standard input output header */
#include<iostream>  /* A predefined library function used for input and output also known as header files */

#include<stdlib.h>  /* An application that defines the appropriate feature test macro */
#include<fstream>   /* A header providing file stream classes including an input and output file stream class */
#include<iomanip>   /* A header providing parametric manipulators */

#include<string>    /* A header for creating a string that contains count characters from other_string */
#include<cstring>   /* A header file defining several functions to manipulate C strings and arrays */
#include<sstream>   /* A header providing string stream classes */
#include<cstdlib>   /* A header defines several general purpose functions, including dynamic memory management */

#include<time.h>    /* A header used to convert the value returned by the clock() */
#include<cassert>   /* A function that defines one macro function that can be used as a standard debugging tool */

using namespace std;    /* Helps avoid writing the std:: */

/*****************************************************************/

/*  A function used for a user to login in the system */
void Account :: loginClient(int username, int password)
{
    int flag = 0;
    
    /*  Obtaining the data from file */
    ifstream file_read("cus_details.txt" ,ios::in);
    while(!file_read.eof())
    {
        
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        if(file_read.eof())
        {
            break;
        }
        if(username == accountNumber && password == passwordCode)
        {
            cout<<"\n Login was sucessfull!" << endl;
            userMenu(username);
            flag = 1;
        }
    }
    
    if(flag == 0 )
    {
        cout<<"\n The username & the password is not correct!" << endl;
        
    }
    file_read.close();
    
}

/*  A function that creates an account for the user */
void Account :: createAccount()
{
    cout << "\n\tEnter your first name: ";
    cin  >> fname;
    cin.clear();
    
    cout << "\n\tEnter your last name: ";
    cin >> lname;
    cin.clear();
    
    string temp_phone;
    cout << "\n\tEnter your 10-digit phone number: ";
    cin  >> temp_phone;
    cin.clear();
    if(temp_phone.length()==10)
    {
        Phone = temp_phone;
        
    }
    else
    {
        while(temp_phone.length() != 10)
        {
            cout << "The phone number must be a 10 digit number" << endl;
            cout << "\n Enter your phone number: " << endl;
            cin  >> temp_phone;
            Phone = temp_phone;
        }
    }
    cout << "\n\tEnter your date of birth: ";
    cin  >> dob;
    cin.ignore();
    
    char atype ='\0';
    cout << "\n\tSelect an account type(Savings S / Other O): ";
    cin  >> atype;
    if(tolower(atype) == 's' )
    {
        typeAccount = "SAVINGS";
    }
    else
    {
        typeAccount = "OTHER";
    }
    accountNumber = getSystemNumber();
    
    cout << "\n\t Your account number is: "<< accountNumber;
    
    cout << "\n\t Enter your 4 digit passcode: ";
    cin  >> passwordCode;
    
    cout << "\n\t Enter your primary balance: ";
    cin  >> balanceAccount;
    
    ofstream file("cus_details.txt",ios::out | ios :: app);
    file << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
    
    putSystemNumber(accountNumber);
    file.close();
}

/*  A function that shows a user's current account balance */
void Account :: CurrentAccountBalance(int clientNO)
{
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    while(file_read)
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(clientNO == accountNumber)
        {
            
            cout << "\n\tCurrent Balance           :"<< balanceAccount << "/-$dollar.";
            cout << "\n\n\n";
        }
    }
    
    file_read.close();
}

/*  A function that searches account details of a user */
void Account :: searchDetails(int user_no)  /* The user_no is used for a user session only as specified user is shown */
{
    int ch;
    int flag = 0;
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    /* cout << "\n\tEnter your account number: ";
    cin >> ch;
    cin.clear(); */
    
    while(file_read)
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(user_no == accountNumber)
        {
            cout << "\n\tAccount Number is: " << accountNumber;
            cout << "\n\tName              :" << fname << " " << lname;
            cout << "\n\tPhone             :" << Phone;
            cout << "\n\tDate of birth     :" << dob;
            cout << "\n\tAccount Type      :" << typeAccount;
            cout << "\n\tBalance           :" << balanceAccount << "/-$dollar.";
            cout << "\n\n\n";
            flag  = 1;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
    }
    file_read.close();
}

/*  A function to delete an account of a user */
void Account ::deleteAccount()
{
    char ch[10];
    char buff;
    int flag = 0;
    string a = "cus_details.txt";
    string b = "temp.txt";
    
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    cout << "\n\tEnter name: ";
    cin  >> ch;
    cin.clear();
    
    while(!file_read.eof())
    {
        
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        if(strcmp(fname,ch) == 0)
        {
            cout << fname << " " << lname << "\t" << dob << "\t" << Phone << "\t" << typeAccount << "\t" << accountNumber << "\t" << balanceAccount << endl;
            flag  = 1;
        }
        else
        {
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
        
    }
    file_temp.close();
    file_read.close();
    copyContent(b,a);
    
    cout << "\n\t Done! An account has been removed!" << endl;
    clearTemporary();
}

/*  Overloading operator to add money to an amount */
void Account :: addMoney(int user_no,int amt)
{
    string a = "cus_details.txt";
    string b = "temp.txt";
    char tr_date[9];
    
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    ofstream tr_write("transec.txt",ios::out | ios::app);
    
    while(!file_read.eof())
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(user_no == accountNumber)
        {
            balanceAccount = balanceAccount + amt;
            /*          _strdate(tr_date); */
            
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
            
            tr_write << accountNumber << " " << tr_date << " " << amt << " " << "$" << endl;
            
        }
        else
        {
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
        }
    }
    
    file_temp.close();
    file_read.close();
    copyContent(b,a);
    cout << "\n\t Done! An amount has been added.\n";
    clearTemporary();
}

/* A function that deducts money from an account */
void Account :: deductAccount(int user_no,int amt)
{
    string a = "cus_details.txt";
    string b = "temp.txt";
    char tr_date[9];
    
    int flag = 0;
    Account();      /* A constructor call to empty variables; */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    ofstream tr_write("transec.txt",ios::out | ios::app);
    while(!file_read.eof())
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(user_no == accountNumber)
        {
            if(balanceAccount != 0 && balanceAccount > amt)
            {
                
                balanceAccount = balanceAccount - amt;
                /*         _strdate(tr_date); //saving current date */
                
                file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
                tr_write << accountNumber << " " << tr_date << " " << amt << " " << "DR" << endl;
                flag = 1;
            }
            else
            {
                cout << "\nYour transaction can not be completed. The balance is zero or less than the withdrawal amount\n!";
                file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
            }
        }
        else
        {
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
        }
    }
    
    file_temp.close();
    file_read.close();
    copyContent(b,a);
    if(flag == 1)
    {
        cout <<"\n\t Done! An amount has been withdrawn." << endl;
    }
    
    clearTemporary();
}

/*  A function that displays a ministatement of an account */
void Account::ministatementAccount(int user_no)
{
    int number,amount,flag = 0,pbalance = 0;
    string date,status;
    char today[9];
    /*  _strdate(today); */
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    while(file_read)
    {
        
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(user_no == accountNumber)
        {
            pbalance = balanceAccount;
        }
    }
    
    file_read.close();
    
    /* To view transactions */
    cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\n\t Mini statement for " << today << endl;
    cout << "\n";
    cout << "\n\tAccount Number: " << accountNumber << endl;
    cout << "\n\n";
    
    ifstream tr_file_read("transac.txt" ,ios::in);
    /* cin.clear(); */
    cout << "\n\t" << "Date" << " | " << "Amount" << " | " << "CR / DR " << endl;
    while(tr_file_read)
    {
        tr_file_read >> number;
        tr_file_read >> date;
        tr_file_read >> amount;
        tr_file_read >> status;
        if(tr_file_read.eof())
        {
            break;
        }
        if(user_no == number)
        {
            cout << "\t" << date << " | " << amount << " | " << status << " | " << endl ;
            flag  = 1;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
    }
    cout << "\n\n";
    cout << "Total primary balance is: " << pbalance << "/." << endl;
    tr_file_read.close();
}

/*  A function to transfer funds from one account to another account */
void Account::fundAccount(int user_no)
{
    int user2_no ,amt =0,flag = 0;
    char ans;
    
    cout << "\nEnter friend's account number: ";
    cin  >> user2_no;
    
    cout << "\nEnter the amount: ";
    cin >> amt;
    
    string a = "cus_details.txt";
    string b = "temp.txt";
    char tr_date[9];
    
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    ofstream tr_write("transec.txt",ios::out | ios::app);
    while(!file_read.eof())
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        if(user2_no == accountNumber)
        {
            cout << "\nAccount owner's name: "<< fname << " " << lname << endl;
            cout << "Enter(Y/N): ";
            cin  >> ans;
            
            if(ans == 'n')
            {
                flag = 1;
                break;
            }
            
            balanceAccount = balanceAccount + amt;
            /*          _strdate(tr_date); */
            
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount <<" " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
            tr_write << accountNumber << " " << tr_date << " " << amt << " " << "CR" << endl;
        }
        else
        {
            file_temp << fname <<"  " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
        }
    }
    
    if(flag == 1)
    {
        cout <<"\n No account found.";
    }
    file_temp.close();
    file_read.close();
    copyContent(b,a);
    cout << "\n\t Done! Amount has been added.\n";
    clearTemporary();
    
    /* To deduct an amount from the main user */
    deductAccount(user_no,amt);
    cout << "\n Money has been successfully transferred!";
}

/* A function that allows a client to put funds as a fixed deposit */
void Account::fdAccount(int user_no)
{
    /* Declaration of variables */
    int flag = 0,f_plan;
    string f_fname,f_lname,f_startdate,f_enddate;
    int f_amount,f_finalAmount = 0,f_time;
    float f_intrestAmount=0;
    float f_rate = 0.06 ;
    char tr_date[9];        /* For automatic date */
    
    cout << "\n\tEnter first name for FD: ";
    cin  >> f_fname;
    cout << "\n\tEnter last name For FD: ";
    cin  >> f_lname;
    cout << "\n\tEnter the amount: ";
    cin  >> f_amount;
    cout << "\n\tEnter a current date: ";
    cin  >> f_startdate;
    
    cout << "\n\t\tSelect your plan:\n";
    cout << "\n\t\t1.Fd For 12 months interest rate is 6%\n";
    cout << "\n\t\t2.Fd For 24 months interest rate is 8%\n";
    cout << "\n\t\t3.Fd For 36 months interest rate is 10%\n";
    cin  >> f_plan;
    cin.clear();
    
    if(f_plan == 1)
    {
        f_rate=0.06;
        f_time=1;
    }
    else if(f_plan == 2)
    {
        f_rate=0.08;
        f_time=2;
    }
    else if(f_plan == 3)
    {
        f_rate=0.1;
        f_time=3;
    }
    else
    {
        cout << "\n\t The default 6% rate has been selected!\n";
        f_rate = 0.06;
        f_time = 1;
    }
    
    f_enddate = addYear(f_startdate,f_time);
    string a = "cus_details.txt";
    string b = "temp.txt";
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    ofstream fd_file("fd.txt",ios::out | ios::app);
    ofstream tr_write("transec.txt",ios::out | ios::app);
    
    /*  _strdate(tr_date), time.h (functions for saving the current date) */
    while(!file_read.eof())
    {
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        
        if(user_no == accountNumber)
        {
            if(balanceAccount != 0 && balanceAccount > f_amount)
            {
                balanceAccount = balanceAccount - f_amount;
                
                f_intrestAmount = f_amount * f_rate * f_time;
                
                f_finalAmount=  f_amount + f_intrestAmount;
                
                cout << "\n\tIntrest rate: " << f_rate << "\n\tInterest Amount: " << f_intrestAmount << "\n\tTotal amount when FD is completed: " << f_finalAmount << endl;
                file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
                fd_file << accountNumber << " " << f_fname << " " << f_lname << " " << f_startdate << " " << f_enddate << " " << f_time << " " << f_amount << " " << f_intrestAmount << " " << f_finalAmount << endl ;
                tr_write << accountNumber << " " << tr_date << " " << f_amount << " " << "$" << endl;
                flag = 1;
            }
            else
            {
                
                cout << "\nFD amount must be less than the primary balance!" << endl;
                file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
            }
        }
        else
        {
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " <<accountNumber << " " << passwordCode << " "<< balanceAccount << endl;
        }
    }
    
    file_temp.close();
    file_read.close();
    fd_file.close();
    copyContent(b,a);
    if(flag == 1)
    {
        cout <<"\n\t Done! The FD has been created.\n";
        
    }
    clearTemporary(); /* Clears the temporary files */
}

/* A function that allows a user to view a fixed deposit */
void Account::viewFD(int user_no)
{
    int flag = 0,f_plan,f_number;
    string f_fname,f_lname,f_startdate,f_enddate;
    int f_amount,f_finalAmount = 0,f_time;
    float f_intrestAmount=0;
    float f_rate =0.0;
    
    ifstream fd_file_read("fd.txt" ,ios::in);
    /* cin.clear(); */
    /* cout << "\n\t" << setw(15) << "AccountNumber" << setw(10) << "Name" << setw(10) << "StartDate" << setw(10) << "EndDate" << setw(10) << "Years" << setw(10) << "Amount" << setw(10) << "Interest" << setw(10) << "FAmount" << endl; */
    cout << "\n" << "Name" << " |" << "StartDate" << " |" << "EndDate" << " |" << "Years" << " |" << "Amount" << " |" << "Interest" << " |" << "FAmount" << endl;
    cout<<string(60,'_');
    while(fd_file_read)
    {
        fd_file_read >> f_number;
        fd_file_read >> f_fname;
        fd_file_read >> f_lname;
        fd_file_read >> f_startdate;
        fd_file_read >> f_enddate;
        fd_file_read >> f_time;
        fd_file_read >> f_amount;
        fd_file_read >> f_intrestAmount;
        fd_file_read >> f_finalAmount;
        
        if(fd_file_read.eof())
        {
            break;
        }
        
        if(user_no == f_number)
        {
            cout << "\n" << f_fname << " " << f_lname << " |" << f_startdate << " |" << f_enddate << " |" << f_time<< " |" <<f_amount << " |" << f_intrestAmount << " |" << f_finalAmount << endl ;
            flag  = 1;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
    }
    fd_file_read.close();
    
}

/* A function that allows a user to view transactions */
void Account::viewTransction(int user_no)
{
    int number,amount,flag = 0;
    string date,status;
    
    ifstream tr_file_read("transec.txt" ,ios::in);
    /* cin.clear(); */
    cout << "\n\t" << "AccountNumber" << " | " << "Date" << " | " << "Amount" << " | " << "CR / DR "<< endl;
    
    while(tr_file_read)
    {
        tr_file_read >> number;
        tr_file_read >> date;
        tr_file_read >> amount;
        tr_file_read >> status;
        if(tr_file_read.eof())
        {
            break;
        }
        if(user_no == number)
        {
            cout << "\t" << number << " | " << date << " | " << amount << " | " << status << " | " << endl;
            flag  = 1;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
    }
    tr_file_read.close();
}

/* A function to update an account */
void Account ::updateAccount(int user_no)
{
    
    int flag = 0;
    string a = "cus_details.txt";
    string b = "temp.txt";
    
    Account();      /* A constructor call to empty variables */
    ifstream file_read("cus_details.txt" ,ios::in);
    ofstream file_temp("temp.txt",ios::out |ios::app);
    
    while(!file_read.eof())
    {
        
        file_read >> fname;
        file_read >> lname;
        file_read >> Phone;
        file_read >> dob;
        file_read >> typeAccount;
        file_read >> accountNumber;
        file_read >> passwordCode;
        file_read >> balanceAccount;
        
        if(file_read.eof())
        {
            break;
        }
        if(user_no == accountNumber)
        {
            cout << "\n\tAccount Number is: " << accountNumber;
            cout << "\n\tEnter the following information for new records:\n";
            
            cout << "\n\n\t New first name: ";
            cin  >> fname;
            cin.clear();
            
            cout << "\n\t New last name: ";
            cin  >> lname;
            cin.clear();
            
            cout << "\n\t New phone number: ";
            cin  >> Phone;
            cin.clear();
            
            cout << "\n\t New date of birth: ";
            cin  >> dob;
            cin.clear();
            
            cout << "\n\t Your current account type: " << typeAccount;
            cout << "\n\t Change type (Savings S / Other O), otherwise press (N): ";
            char ans;
            cin  >> ans;
            cin.clear();
            if(tolower(ans) == 'n')
            {
                cout << "\n\t No changes have been made to your account type!\n ";
            }
            else if(tolower(ans) == 's')
            {
                typeAccount = "SAVINGS";
            }
            else
            {
                typeAccount = "OTHER";
            }
            file_temp << fname <<  " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
            flag  = 1;
        }
        else
        {
            file_temp << fname << " " << lname << " " << Phone << " " << dob << " " << typeAccount << " " << accountNumber << " " << passwordCode << " " << balanceAccount << endl;
        }
    }
    if(flag != 1)
    {
        cout << "\n\tNo record found.";
    }
    file_temp.close();
    file_read.close();
    copyContent(b,a);
    
    cout << "\n\t Done! Your account details has been updated. Thank you.\n";
    clearTemporary();
}

/* A function to display the user menu */
void Account::userMenu(int user_session)
{
    int ch;
    int amount = 0;
    Account call;
start:do
{
    cout << "Welcome! Your account number is>>>>>>  " << user_session << endl;
    cout << "\n\t 1. View Your Account.";
    cout << "\n\t 2. Update Your Details.";
    cout << "\n\t 3. Transfer Funds.";
    cout << "\n\t 4. Withdraw Funds.";
    cout << "\n\t 5. Add Money.";
    cout << "\n\t 6. View Transaction.";
    cout << "\n\t 7. Close / Delete an Account.";
    cout << "\n\t 8. Create a Fixed Deposit";
    cout << "\n\t 9. View All Fixed Deposit";
    cout << "\n\t 10.Account MiniStatement";
    cout << "\n\t 0. Exit";
    
    cout << "\n\t Select one of the ten options (1-10): ";
    if(cin >> ch)
    {
        switch (ch)
        {
            case 1:
                system("clear");
                call.searchDetails(user_session);
                break;
                
            case 2:
                system("clear");
                call.updateAccount(user_session);
                break;
                
            case 3:
                system("clear");
                call.fundAccount(user_session);
                break;
                
            case 4:
                cout << "\n\tEnter an amount to withdraw: ";
                cin  >> amount;
                
                call.deductAccount(user_session,amount);
                break;
                
            case 5:
                cout << "\n\tEnter an amount to add: ";
                cin  >> amount;
                call.addMoney(user_session,amount);
                call.CurrentAccountBalance(user_session);
                break;
                
            case 6:
                call.viewTransction(user_session);
                break;
                
            case 7:
                call.deleteAccount();
                break;
            case 8:
                call.fdAccount(user_session);
                break;
            case 9:
                call.viewFD(user_session);
                break;
            case 10:
                call.ministatementAccount(user_session);
                break;
                
            default :
                cout << "\n\tWrong choice has been entered. \n";
                break;
        }
    }
    else
    {
        cout << "\n\t Please enter digits only!";
        system("PAUSE");
        cin.clear();
        cin.ignore();
        ch = 15;
    }
}
    while(ch != 0);
    
}

