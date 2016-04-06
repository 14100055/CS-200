#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int compareString(char string1[], char string2[]);

int compareString(char string1[], char string2[], int n);

void stringCopy(char destination[], char src[]);

char* findString(char* str1, char* str2);

bool findStr(const char* str1, const char* str2);

void stringCopy(char destination[], char src[], int n);

char* stringCat(char* destination, const char* src);

char* stringCat(char* destination, const char* src, int n);

char* myStrtok(char* inputString, char* separatorList, char* oneToken);

void grep(char* srcline, char* pattern);

void sortStrings(char strings[][20], int count);
