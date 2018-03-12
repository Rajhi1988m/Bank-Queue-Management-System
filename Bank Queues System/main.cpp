//
//  main.cpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

/*****************************************************************/
/*                 HEADER FILE USED IN PROJECT                   */
/*****************************************************************/

#include "User.hpp"     /* Declares the User class */
#include "Account.hpp"  /* Declares the Account class */
#include "Manually.hpp" /* Declares the Manually class */

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

/*****************************************************************/
/*    	          THE MAIN FUNCTION OF PROGRAM                   */
/*****************************************************************/


int main(int argc, const char * argv[]) {
    
    /****************************************************************/
    /*                        THE DATATYPE                          */
    /****************************************************************/
    
    int input;  /* Used for inputing one of the options from the list */
    int login_state = 0;    /* To login the system */
    int user;   /* To enter a username */
    int pass;   /* To enter a password */
    Account call1;  /* An object to call account function */
    Manually call2; /* An object to call manually function */
    
    do{
        system("clear");    /* Helps to clear the screen in windows */
        
        /*****************************************************************/
        /*    	           THE MAIN SCREEN IN PROGRAM                    */
        /*****************************************************************/
        
        cout << "*************************************************************" << endl;
        cout << "*                                                           *" << endl;
        cout << "*                  Bank Management System                   *" << endl;
        cout << "*                Kentucky State University                  *" << endl;
        cout << "*             Advanced Programming/Data Structure           *" << endl;
        cout << "*                                                           *" << endl;
        cout << "*************************************************************" << endl;
        cout << "*                      MAIN MENU                            *" << endl;
        cout << "*                                                           *" << endl;
        cout << "*************************************************************" << endl;
        cout << "\n		1 	 Login To Your Account                            ";
        cout << "\n		2	 Open An Account                                  ";
        cout << "\n		3	 Ask for Help                                     ";
        cout << "\n	    4	 Exit                                             ";
        cout << "*************************************************************" << endl;
        cout << "\nPlease enter one of the four options to proceed: ";
        
        /*****************************************************************/
        /*    	          INSERT ONE OF THE FOUR OPTIONS                 */
        /*****************************************************************/
        
        if(cin >> input )
        {
            switch (input)
            {
                case 1:
                    cout << "\n\t Insert Your Account Number:";
                    cin  >> user;
                    cout << "\n\t Insert 4-digit Password:";
                    cin  >> pass;
                    system("clear");
                    call1.loginClient(user,pass);
                    /* cout<<"\n\t\tWork Is In Progress"; */
                    
                    break;
                case 2:
                    call1.createAccount();
                    break;
                    
                case 3:
                    /*	cout<<"\nWork Is In Progress !"; */
                    call2.guidUser();
                    system("pause");
                    break;
            }
        }
        else
        {
            cout<<"\n\t Please Input Only Digits ! Press Enter To Continue";
            system("PAUSE");
            cin.clear();
            cin.ignore();
            input = 15 ;
        }
        
    }
    while(input !=0);
    
    return 0;
}
