#include "fileIO.h"
//#include <iostream>
//#include <fstream>
//using namespace std;

/*
//	Code for reading a text file, storing it in memory and returning a (character) pointer to its memory location.
*/
ifstream file;
char line[200];
bool openFile(char * filename) 
{
	//char * memblock;
  	file.open(filename, ios::in);
	if(file.is_open())
		return true;
	return false;
}

char* readLine()
{
  	if (file.is_open())
  	{	
		if(file)
		{
			file.getline(line, 200);
			if (strlen(line)>0)
				return line;
			else
				return NULL;
		}
		else
			return NULL;
		/*long size, begin, end;
		begin = file.tellg();
		file.seekg (0, ios::end);
		end = file.tellg();
		size = end - begin;
   		memblock = new char [size];
    		file.seekg (0, ios::beg);
    		file.read (memblock, size);
    		file.close();*/
 	 }
  	else 
	{
		cout << "Can't read from file!";
		return NULL;
	}
}

void closeFile()
{
	if(file.is_open())
		file.close();
}
