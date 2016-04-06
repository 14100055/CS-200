/********************************************************/
/*                                                      */
/*      Name: Task3.cpp                                 */
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011                       */
/*      Purpose: Find String	                        */
/*                                                      */
/********************************************************/

#include "Assignment3.h"

char* findString(char* str1, char* str2)
{
	int counter=0;									//Search to see if the 1st letter of the 2nd string
	int same=0;										//matches with any of the letters of the 1st string.
													//If it matches then check if the next letters of
	while( (*(str1+counter)!= '\0' ) )				//1st and 2nd match with each other.
	{
		if(*(str1+counter)==*(str2))
		{
			for(int i=0; *(str2+i)!='\0';i++)
			{
				if(*(str1+counter+i)==*(str2+i))
				{
					same=1;
				}
				else
				{
					same=0;
					break;
				}
			}
		}
		if(same==1)
		{
			return (str1+counter);
		}

		counter++;
	}
	return NULL;
}
