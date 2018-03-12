//
//  Manually.cpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

/*****************************************************************/
/*                   HEADER FILE USED IN PROJECT                 */
/*****************************************************************/

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

/* A function that gives an instructions to an user on how to open a new account */
void Manually::guidUser()
{
    cout << "*************************************************************" << endl;
    cout << "*                                                           *" << endl;
    cout << "*                  Bank Management System                   *" << endl;
    cout << "*                Kentucky State University                  *" << endl;
    cout << "*             Adv Programming/Data Structure                *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*************************************************************" << endl;
    cout << "*                   MAIN INSTRUCTIONS                       *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*************************************************************" << endl;
    cout << "* \nThis Software is for the Education Use Only *\n";
    cout << "*************************************************************" << endl;
    cout << endl;
    
    cout.setf(ios::left);
    cout << setw(10) << "Application Name" << ":" << setw(20) << "Banking System" << endl;
    cout << setw(10) << "Platform" << ":" << setw(20) << "Windows, Linux, Mac OS" << endl;
    cout << setw(10) << "Language is" << ":" << setw(20) << "C++" << endl;
    cout << setw(10) << "Course Number is" << ":" << setw(20) << "COS 506" << endl;
    cout <<endl <<endl;
    
    cout << "* PROGRAM INSTRUCTIONS:" << endl;
    cout << string(26,'-') << endl;
    cout << "1. How can you open a new account?" << endl;
    cout << "-> Use the second option \"Create new Account\" " << endl;
    cout << "*************************************************************" << endl;
}
