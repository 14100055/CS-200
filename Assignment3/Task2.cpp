/********************************************************/
/*                                                      */
/*      Name: Task2.cpp                                 */
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011                       */
/*      Purpose: Copy Strings	                        */
/*                                                      */
/********************************************************/

#include "Assignment3.h"

void stringCopy(char destination[], char source[])
{
	int counter=0;									//Copy element by element and then add the NULL character.

	while(source[counter]!='\0')
	{
		destination[counter]=source[counter];
		counter++;
	}
	destination[counter]='\0';
}


void stringCopy(char destination[], char source[], int n)
{
	int counter=0;									//Copy element by element till end of string
													//or "n" number of characters. Then add the
	while( (source[counter]!='\0')&&(counter<n) )	//NULL character.
	{
		destination[counter]=source[counter];
		counter++;
	}
	destination[counter]='\0';
}
