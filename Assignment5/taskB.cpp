#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

void fillVector(istream& in);
bool compPrefix(const char* word);
bool compRoot(const char* word, bool prefixCut);
bool compSuffix(const char* word, bool rootCut);

vector<string> prefix, root, suffix, test;

int main()
{
	fillVector(cin);

	for(int i=0; i<test.size(); i++)
	{
		if(compPrefix(test[i].c_str()))
		{
				cout<<"yes";
		}
		else
		{
			cout<<"no";
		}

		if(i!=(test.size()-1))
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
		prefix.push_back(s);
	}

	getline(in, s);
	num = atoi(s.c_str());
	for(int i=0; i<num; i++)
	{
		getline(in, s);
		root.push_back(s);
	}

	getline(in, s);
	num = atoi(s.c_str());
	for(int i=0; i<num; i++)
	{
		getline(in, s);
		suffix.push_back(s);
	}

	getline(in, s);
	num = atoi(s.c_str());
	for(int i=0; i<num; i++)
	{
		getline(in, s);
		test.push_back(s);
	}
}

bool compPrefix(const char* word)
{
	int len;
	for(int i=0; i<prefix.size(); i++)
	{
		len = prefix[i].length();

		if(strncmp(word, prefix[i].c_str(), len)==0)
		{
			if(compRoot(word+len, false))
			{
				return true;
			}
		}

		len--;
		if(strncmp(word, prefix[i].c_str(), len)==0)
		{
			if(compRoot(word+len, true))
			{
				return true;
			}
		}
	}
	return false;
}

bool compRoot(const char* word, bool prefixCut)
{
	int len;

	for(int i=0; i<root.size(); i++)
	{
		len = root[i].length();

		if(strncmp(word, root[i].c_str(), len)==0)
		{
			if(compSuffix(word+len, false))
			{
				return true;
			}
		}
		len--;
		if(strncmp(word, root[i].c_str(), len)==0)
		{
			if(compSuffix(word+len, true))
			{
				return true;
			}
		}

		if(!prefixCut)
		{
			if(strncmp(word, root[i].c_str()+1, len)==0)
			{
				if(compSuffix(word+len, false))
				{
					return true;
				}
			}
			len--;
			if(strncmp(word, root[i].c_str()+1, len)==0)
			{
				if(compSuffix(word+len, true))
				{
					return true;
				}
			}
			if(len==0)
			{
				if(compSuffix(word, true))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool compSuffix(const char* word, bool rootCut)
{
	for(int i=0; i<(suffix.size()); i++)
	{
		if(strcmp(word, suffix[i].c_str())==0)
		{
			return true;
		}

		if(!rootCut)
		{
			if(strcmp(word, suffix[i].c_str()+1)==0)
			{
				return true;
			}
		}
	}
	return false;
}
