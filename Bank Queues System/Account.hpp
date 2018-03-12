//
//  Account.hpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

/*****************************************************************/
/*                   HEADER FILE USED IN PROJECT                 */
/*****************************************************************/

#include "User.hpp" /* Declares the User class */

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

/****************************************************************/

/****************************************************************/
/*                   CLASS USED IN PROJECT                      */
/****************************************************************/

class Account : public User /* The class account will inherit from the class User */
{
/* Declare datatypes by protected to be used by the drive class */
protected:
    int accountNumber ;
    int passwordCode ;
    int balanceAccount;
    string typeAccount;     /* For the account type */
    
public:
    /****************************************************************/
    /*              A FUNCTION TO WRITE IN THE FILE                 */
    /****************************************************************/
    
    Account()   /* A constractor */
    {
        accountNumber = 0;
        balanceAccount = 0;
        passwordCode = 0;
    }
    ~Account(){}    /* A destructor */
    
    void CurrentAccountBalance(int);    /* A function to show the current account balance */
    void createAccount();               /* A function to create a new bank account */
    void showDetails();                 /* A function that shows an account details */
    void searchDetails(int);            /* A function to search details of a particular client */
    void deleteAccount();               /* A function to delete an account */
    void updateAccount(int);            /* A function to update an account */
    void loginClient(int,int);          /* A function for a client to login in the system */
    void addMoney(int,int);             /* A function to add money in the account */
    void deductAccount(int,int);	 	/* A function to deduct money from the account */
    void fdAccount(int);                /* A function to calculate an interest rate */
    void viewFD(int);                   /* A function to view an account details */
    void viewTransction(int);           /* A function to view all transections of a client */
    void fundAccount(int);              /* A function that allows tranfering of funds between two clients */
    void ministatementAccount(int);     /* Afunction to view a ministatement of an account */
    void userMenu(int);                 /* A function for the client menu */
    
};  /* Class ends here */

#endif /* Account_hpp */
