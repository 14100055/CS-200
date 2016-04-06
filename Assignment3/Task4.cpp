/********************************************************/
/*                                                      */
/*      Name: Task4.cpp                                 */
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011						*/
/*      Purpose: Concatenate Strings					*/
/*                                                      */
/********************************************************/

#include "Assignment3.h"

char* stringCat(char* destination, const char* source)
{
	int counter1=strlen(destination), counter2=0;			//Starting from the NULL character of
															//destination string, we add the characters
	while( *(source+counter2)!='\0')						//present in source element by element.
	{														//Then we exit and and NULL character at the end.
		*(destination+counter1)=*(source+counter2);

		counter1++;
		counter2++;
	}
	*(destination+counter1)='\0';
	return destination;
}


char* stringCat(char* destination, const char* source, int n)
{
	int counter1=strlen(destination), counter2=0;			//Same as above except that now we check to
															//concatenate upto "n" number of characters.
	while( ( *(source+counter2)!='\0')&&(counter2<n) )
	{
		*(destination+counter1)=*(source+counter2);

		counter1++;
		counter2++;
	}
	*(destination+counter1)='\0';
	return destination;
}
