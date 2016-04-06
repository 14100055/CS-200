#include "Assignment3.h"

int main()
{
	//int compare;
	//char string1[]="metro politan";
	//char string2[]="Metropolitan";

	//compare=compareString(string1, string2);
	//const int size=5;

	//char destination[2*size]="I am ";
	//char source[]="S";

	//cout<<destination<<endl;
	//cout<<source<<endl<<endl;

	//stringCat(destination, source, 2);

	//const int size=5;

	//char* same;
	//char str1[]="I like this food!";
	//char str2[]="is";
	//char* ptr1 = &str1[0];
	//char* ptr2 = &str2[0];

	//same=findString(str1, str2);
	//cout<<same<<endl;

	//cout<<str1<<endl;
	//cout<<str2<<endl<<endl;

	//stringCopy(destination, source);

	//for(int i=0; i<(2*size); i++)
	//{
	//	cout<<destination;
	//}

	//for(int i=0; i<50; i++)
	//{
	//	cout<<str2<<endl;
	//}

	//cout<<compare<<endl;
	//cout<<same<<endl;

	char tokenizethis[] = "rere,$$$fdfd$556&****,, 2.3.4.4";
	char* ptr = tokenizethis;
	char token[80]=" ";

	while(ptr)
	{
		ptr = myStrtok(ptr, " ,\t:.:$", token);
		cout<<token<<endl;
	}

/*
	int j=0;
	char arrStr[][20]={"watermelon", "banana", "peaches", "apple", "aPricot", "mango"};

	for(int i=0; i<6; i++)
	{
		for(int j=0; j<20; j++)
		{
			cout<<arrStr[i][j];
		}
		cout<<endl;
	}

	cout<<endl<<"Sorting! Please wait..."<<endl<<endl;
	sortStrings(arrStr, 6);

	for(int i=0; i<6; i++)
	{
		for(int j=0; arrStr[i][j]!='\0'; j++)
		{
			cout<<arrStr[i][j];
		}
		cout<<endl;
	}
*/

	string str1;
	string str2;

	cout<<"Enter 1st large string: ";
	getline(cin, str1);

	cout<<"Enter 2nd smaller string: ";
	getline(cin, str2);

	if( findStr( str1.c_str(), str2.c_str() ) )
	{
		cout<<"A substring!"<<endl;
	}
	else
	{
		cout<<"Not a match!"<<endl;
	}

	return 0;

}
