/********************************************************/
/*                                                      */
/*      Name: Task5.cpp                                 */
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011                       */
/*      Purpose: Tokenize		                        */
/*                                                      */
/********************************************************/

#include "Assignment3.h"

char* myStrtok(char* inputString, char* separatorList, char* oneToken)
{
	int counter1=0, counter2=0;																								//Find the length of the separator list.
	int listLength=strlen(separatorList);																					//For each character in the input string,
																															//check if it matches any of the separator
	while( *(inputString+counter1)!='\0')																					//list delimiters. If it matches then have
	{																														//it check if the next character matches
		for(int i=0; i<listLength; i++)																						//any of the delimiters and keep going
		{																													//till the length of the string. If the next
			if( *(inputString+counter1)==*(separatorList+i) )																//character matches then increase counter.
			{
				for(int j=counter1; j<strlen(inputString); j++)																//Eventually a non-delimiter will appear
				{																											//and we counter will not increase. When loop
					for(int k=0; k<listLength; k++)																			//ends, we place a null character at the end
					{																										//of our token. And return pointer of next
						if( *(inputString+counter1)==*(separatorList+k))														//non-delimiter. By default
						{																									//(i.e. if the character is a non-delimiter)
							counter1++;																						//place character in the token and increment
						}																									//our counters. For the last token we add a
					}																										//NULL character (in final if-check).
				}
				*(oneToken+counter2)='\0';
				return (inputString+counter1);
			}
		}

		*(oneToken+counter2)=*(inputString+counter1);
		counter1++; counter2++;
	}

	if (*(inputString+counter2)=='\0')
	{
		*(oneToken+counter1)='\0';
	}
	return NULL;
}
