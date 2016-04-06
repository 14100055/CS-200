#include "Assignment3.h"

bool findStr(const char* str1, const char* str2)
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
			return true;
		}
		counter++;
	}
	return false;
}
