//
//  Manually.hpp
//  Bank_Queues_System
//
//  Created by Mohammed Rajhi | Drashti Patel on 4/15/17.
//  Copyright © 2017 Mohammed Rajhi | Drashti Patel. All rights reserved.
//

#ifndef Manually_hpp
#define Manually_hpp

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

class Manually
{
public:
    
    /***************************************************************/
    /*    	         A FUNCTION TO WRITE IN THE FILE               */
    /***************************************************************/
    
    void guidUser();    /* A function that guides a user to understand how to work with the system */
};  /* Class ends here */

#endif /* Manually_hpp */
