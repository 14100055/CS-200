#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
/*
// read_text_file take in the file path (of file name in current directory)
// reads it and stores its contents in memory. It returns the pointer to the
// memory location where the contents of the file are stored.
*/
bool openFile(char*);
char* readLine();
void closeFile();
char * read_text_file(char * filename);
