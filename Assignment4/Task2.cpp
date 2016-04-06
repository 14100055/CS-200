//==============================================
//	Task 2: "Hiding in plain sight"
//
//	Function: put all the bit planes together
//==============================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//opening an image, reading through the header for all images
	//and then opening and writing it into recovered.bmp
	char header[54];

	ifstream fin0;
	fin0.open("secret0.bmp", ios::in | ios::binary);
	fin0.read(header, 54);

	ifstream fin1;
	fin1.open("secret1.bmp", ios::in | ios::binary);
	fin1.read(header, 54);

	ifstream fin2;
	fin2.open("secret2.bmp", ios::in | ios::binary);
	fin2.read(header, 54);

	ifstream fin3;
	fin3.open("secret3.bmp", ios::in | ios::binary);
	fin3.read(header, 54);

	ifstream fin4;
	fin4.open("secret4.bmp", ios::in | ios::binary);
	fin4.read(header, 54);

	ifstream fin5;
	fin5.open("secret5.bmp", ios::in | ios::binary);
	fin5.read(header, 54);

	ifstream fin6;
	fin6.open("secret6.bmp", ios::in | ios::binary);
	fin6.read(header, 54);

	ifstream fin7;
	fin7.open("secret7.bmp", ios::in | ios::binary);
	fin7.read(header, 54);

	ofstream recovered;
	recovered.open("recovered.bmp", ios::out | ios::binary);
	recovered.write(header, 54);

	char buffer;
	char x0, x1, x2, x3, x4, x5, x6, x7;
	char final;

	while( !fin0.eof() )
	{
		//reading a byte from each image, then getting
		//least significant bit from byte and then putting
		//it in the correct significant place.
		fin0.read(&buffer, 1);
		x0 = (buffer & 1);

		fin1.read(&buffer, 1);
		x1 = (buffer & 1)<<1;

		fin2.read(&buffer, 1);
		x2 = (buffer & 1)<<2;

		fin3.read(&buffer, 1);
		x3 = (buffer & 1)<<3;

		fin4.read(&buffer, 1);
		x4 = (buffer & 1)<<4;

		fin5.read(&buffer, 1);
		x5 = (buffer & 1)<<5;

		fin6.read(&buffer, 1);
		x6 = (buffer & 1)<<6;

		fin7.read(&buffer, 1);
		x7 = (buffer & 1)<<7;

		//putting all the 8 bits into one byte and then writing out
		final = x0 | x1 | x2 | x3 | x4 | x5 | x6 | x7;

		recovered.write(&final, 1);

	}

	//closing all
	fin0.close();
	fin1.close();
	fin2.close();
	fin3.close();
	fin4.close();
	fin5.close();
	fin6.close();
	fin7.close();

	recovered.close();
}
