/********************************************************/
/*                                                      */
/*      Name: Task7.cpp                                 */
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011                       */
/*      Purpose: Sort A String Array					*/
/*                                                      */
/********************************************************/

#include "Assignment3.h"

void sortStrings(char strings[][20], int count)
{
	char temp[20]="";										//Make a temporary character array that will store
	for(int i=0; i<(count-1); i++)							//the string. Call compare function. If it returns
	{	 													//1, then that means that the 1st string is larger
		for(int j=0; j<(count-1-i); j++)					//than 2nd string. Therefore, we would need to swap.
		{													//Calling copy function so then that we can swap strings.
			if(compareString(strings[j], strings[j+1])==1)	//Sorting is BubbleSort, in ascending order.
			{
				stringCopy(temp, strings[j]);
				stringCopy(strings[j], strings[j+1]);
				stringCopy(strings[j+1], temp);
			}
		}
	}
}

////FUNCTIONS WRITTEN FROM OTHER TASKS////////////////////////////////////////////////////////////////

////COMPARE STRING - TASK 1///////////////////////////////////////////////////////////////////////////

int compareString(char string1[], char string2[])
{
	int x=strlen(string1); int y=strlen(string2);
	int counter=0;
	char c1, c2;

	while( !( (counter==(x))&&(counter==(y)) ) )
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

////COPY STRING - TASK 2//////////////////////////////////////////////////////////////////////////////

void stringCopy(char destination[], char source[])
{
	int counter=0;

	while(source[counter]!='\0')
	{
		destination[counter]=source[counter];
		counter++;
	}
	destination[counter]='\0';
}
