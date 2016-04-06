//=================================================
//	Task 1: "Lost in formatting"
//
//	Function: recovering images from memcard.raw
//=================================================

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//initialization
	char fileName[10];
	int fileNumber = 0;

	ifstream infile;
	infile.open("memcard.raw", ios::in | ios::binary);

	ofstream outfile;

	//making a temp array so then that we can compare AND making starting sequence of image
	char temp[4];

	int seq1[]={255, 216, 255, 224};
	int seq2[]={255, 216, 255, 225};

	char charSeq1[4];
	char charSeq2[4];

	for(int i=0; i<4; i++)
	{
		//storing the sequence in a char array
		charSeq0[i]=seq1[i];
		charSeq2[i]=seq2[i];

		//reading the 1st four bytes into temp
		infile.read(&temp[i], 1);
	}

	while( !infile.eof() )
	{
		//comparing to see if sequence has been found
		if( (temp[0]==charSeq1[0]) && (temp[1]==charSeq1[1]) && (temp[2]==charSeq1[2]) && ( (temp[3]==charSeq1[3]) || (temp[3]==charSeq2[3]) ) )
		{
			//closing previous file before opeing a new one again
			if(fileNumber>0)
			{
				outfile.close();
			}
			//making name of file and opening output
			fileNumber++;
			sprintf(fileName, "%d.jpg", fileNumber);
			outfile.open(fileName, ios::out | ios::binary);
		}

		//if there is a file then write into output file
		if(fileNumber>0)
		{
			outfile.write(&temp[0], 1);
		}

		//like a snake (of 1st assignment) traversing the file by making each
		//index take the value of next index and "reading" into last index
		temp[0] = temp[1];
		temp[1] = temp[2];
		temp[2] = temp[3];
		infile.read(&temp[3], 1);
	}
	//closing the last file
	outfile.close();
}
