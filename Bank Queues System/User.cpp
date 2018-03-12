//
//  User.cpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

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

/*****************************************************************/

/* This function is used to clear the screen */
void User::clearScreen()
{
    
    cout << string( 100, '\n' );
}

/* This function is used to copy the contents */
void User::copyContent(string num1,string num2)
{
    char ch;
    int flag = 0;
    ifstream temp_read(num1.c_str(),ios :: in);
    ofstream file_write(num2.c_str(),ios::out);
    while(!temp_read.eof())
    {
        temp_read.get(ch);
        file_write.put(ch);
        flag = 1;
    }
    if(flag != 1)
    {
        cout <<"\n\tThere is an error in file... !";
    }
    
}

/* A function for an account number automation */
int User::getSystemNumber()
{
    
    int number;
    ifstream number_read("number.txt",ios::in);
    number_read >>number;
    return number;
}

/* A function to put a system number */
void User::putSystemNumber(int number1)
{
    
    number1 = number1+1;
    ofstream number_write("number.txt",ios::out);
    number_write <<number1;
}

/* A function to clear temoprary files */
void User::clearTemporary()
{
    
    ofstream temp_write("tmp.txt",ios :: out);
    temp_write <<" ";
    temp_write.close();
}

/* A function that calculates a year */
string User::addYear(string date1, int year)
{
    int add ;
    string date2;
    stringstream ss(date1.substr(6,4));
    stringstream ss2(date1.substr(0,6));
    stringstream ss3;
    string s2; /* For the remaining years */
    ss2 >> s2;
    ss >> add;
    add = add + year;
    ss3 << add;
    date2 = s2 + ss3.str();
    
    return date2;
}
