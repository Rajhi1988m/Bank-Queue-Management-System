//
//  User.hpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

/*****************************************************************/
/*                   HEADER FILE USED IN PROJECT                 */
/*****************************************************************/

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
/*                   CLASS USED IN PROJECT                       */
/*****************************************************************/

class User
{
protected:
    
    /* Datatypes that can be used in drive class */
    char fname[10],lname[10];
    string Phone;
    string dob;
    
public:
    
    /*****************************************************************/
    /*                A FUNCTION TO WRITE IN THE FILE                */
    /*****************************************************************/
    
    User()      /* A constructor */
    {
        Phone = '\0';   /* This is the NULL character, which can be found on the ASCII table */
        dob = '\0';     /* This is the NULL character, which can be found on the ASCII table */
    }
    ~User()     /* A destructor */
    {}
    /*****************************************************************/
    
    void clearTemporary();      /* A function for clearing temporary files */
    void copyContent(string num1,string num2);      /* Global declaration */
    void putSystemNumber(int number1);      /* A function to put a system number */
    int getSystemNumber();      /* A function to get an account number automation */
    string addYear(string date1,int year);      /* A function to calculate a year */
    void clearScreen();     /* A function to clear the screen */
    
}; /* Class ends here */

#endif /* User_hpp */
