/********************************************************/
/*                                                      */
/*      Name: Task6.cpp (taken from mygrep.cpp)			*/
/*      Author: Saad Naveed Ismail (2014-10-0055)       */
/*      Date: 4th, November, 2011                       */
/*      Purpose: Grep Function	                        */
/*                                                      */
/********************************************************/

#include "fileIO.h"
#include "Assignment3.h"

/************************************/
/* 	The program entry point			*/
/************************************/
int main(int args, char** arg)
{
	// Implement main program here.
	// Make sure the user has entered the correct number of arguments
	// Call grep function with suitable arguments.

	if ( args==3 )
	{
		grep(arg[1], arg[2]);
	}
	else
	{
		cout<<"ERROR"<<endl;
	}

}

/****************************************************************/
/*	Prints all lines in "filename" that contain the "word"		*/
/****************************************************************/

void grep(char * word, char * filename)
{
	char* lion;		// The string that will hold each consecutive line
	// Open the file
	if(openFile(filename))
	{
		// If the file was successfully opened, read it line by line
		while(lion = readLine())
		{
			// The function displays all lines on the screen that contain "word"
			if(findString(lion, word)!=NULL)
				cout<< lion << endl;
		}
		// No more lines in the file, so just close it
		closeFile();
	}
	else
		cout << "Can't open file for reading: " << filename << endl;
}


////FUNCTIONS WRITTEN FROM OTHER TASKS//////////////////////////////////////////////////////////

////FIND STRING - TASK 3////////////////////////////////////////////////////////////////////////

char* findString(char* str1, char* str2)
{
	int counter=0;
	int same=0;

	while( (*(str1+counter)!= '\0' ) )
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
