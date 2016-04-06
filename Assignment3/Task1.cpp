/********************************************************/
/*														*/
/*		Name: Task1.cpp									*/
/*		Author: Saad Naveed Ismail (2014-10-0055)		*/
/*		Date: 4th, November, 2011						*/
/*		Purpose: Compare Strings						*/
/*														*/
/********************************************************/

#include "Assignment3.h"

int compareString(char string1[], char string2[])
{
	int x=strlen(string1); int y=strlen(string2);			//Find length of strings and start running loop until length of strings.
	int counter=0;											//Then character by character compare the lower case versions. If
	char c1, c2;											//string2 is larger then return -1.If string1 is larger then return 1.
															//If the two strings are  exactly the same it should return 0
	while( !( (counter==(x))&&(counter==(y)) ) )			//(which is the default return value).
	{
		c1=tolower(string1[counter]);
		c2=tolower(string2[counter]);

		if(c1<c2)
		{
			return -1;
		}
		else if(c1>c2)
		{
			return 1;
		}
		counter++;
	}
	return 0;
}


int compareString(char string1[], char string2[], int n)
{
	int x=strlen(string1); int y=strlen(string2);
	int counter=0;
	char c1, c2;

	while( ( !( (counter==x)&&(counter==y) ) ) && (counter<n) )		//Same functionality as above except also add condition
	{																//of compare till "n" number of characters.
		c1=tolower(string1[counter]);
		c2=tolower(string2[counter]);

		if(c1<c2)
		{
			return -1;
		}
		else if(c1>c2)
		{
			return 1;
		}
		counter++;
	}
	return 0;
}
