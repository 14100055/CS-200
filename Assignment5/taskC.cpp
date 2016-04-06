#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

void fillVector(istream& in);
int numMatch(const char* word1, const char* word2);

vector<string> dictionary, test;

int main()
{
	fillVector(cin);

	int len = dictionary.size();
	int matches = 0;
	int maxMatch = 0;
	int index = 0;

	for(int i=0; i<test.size(); i++)
	{
		matches = 0;
		maxMatch = 0;

		for(int j=0; j<len; j++)
		{
			matches = numMatch( test[i].c_str(), dictionary[j].c_str() );

			if(matches==-10)
			{
				maxMatch = matches;
				cout<<test[i];
				break;
			}

			if(matches>maxMatch)
			{
				maxMatch = matches;
				index = j;
			}
		}

		if(maxMatch>0)
		{
			cout<<dictionary[index];

			for(int j=1; j<(min(5, len-index)); j++)
			{
				matches = numMatch(test[i].c_str(), dictionary[index+j].c_str());

				if(matches==maxMatch)
				{
					cout<<" "<<dictionary[index+j];
				}
				else
				{
					break;
				}
			}
		}

		if(maxMatch==0)
		{
			cout<<"0";
		}

		if(i != test.size()-1)
		{
			cout<<endl;
		}
	}

	return 0;
}

void fillVector(istream& in)
{
	string s;
	int num;

	getline(in, s);
	num = atoi(s.c_str());
	for(int i=0; i<num; i++)
	{
		getline(in, s);
		dictionary.push_back(s);
	}

	getline(in, s);
	num = atoi(s.c_str());
	for(int i=0; i<num; i++)
	{
		getline(in, s);
		test.push_back(s);
	}
}

int numMatch(const char* word1, const char* word2)
{
	int counter = 0;

	for(int i=0; i<max(strlen(word1), strlen(word2)) ; i++)
	{
		if(*(word1+i)==*(word2+i))
		{
			counter++;
		}
		else
		{
			return counter;
		}
	}
	return -10;
}
