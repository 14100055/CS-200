#include "InputValidate.h"

Date InputValidate::ReadDate(const std::string& prompt)
{
	while(true)
	{
		cout<<prompt;
		string tempd, tempm, tempy;
		cout<<"(Format: dd/mm/yyyy): ";
		if(!getline(cin, tempd,'/'))
			continue;
		if(!getline(cin, tempm,'/'))
			continue;
		if(!getline(cin, tempy,'\n'))
			continue;
		if(tempd.size()!=2||tempm.size()!=2||tempy.size()!=4)
			continue;
		//check that if all inputs of DATE are numbers (and not letters)
		if( (tempd[0]<48 || tempd[0]>57 || tempd[1]<48 || tempd[1]>57) || (tempm[0]<48 || tempm[0]>57 || tempm[1]<48 || tempm[1]>57) || (tempy[0]<48 || tempy[0]>57 || tempy[1]<48 || tempy[1]>57 || tempy[2]<48 || tempy[2]>57 || tempy[3]<48 || tempy[3]>57) )
			continue;

		int d, m, y;
		d = atoi(tempd.c_str());
		m = atoi(tempm.c_str());
		y = atoi(tempy.c_str());
		//if input of month is larger than 13 (then ask for input again)
		if(m<1 || m>12)
			continue;
		//if certain months have more than 31 days (then ask for input again)
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			if(d<1 || d>31)
				continue;
		//if its a leap year and February has more than 29 days (then ask for input again)
		if((y%4)==0)
			if(m==2)
				if(d<1 || d>29)
					continue;
		//for other years if it has more than 28 days (then ask for input again)
		if(m==2)
			if(d<1 || d>28)
				continue;
		//if certain months have more than 30 days (then ask for input again)
		if(m==4 || m==6 || m==9 || m==11)
			if(d<1 || d>30)
				continue;

		Date A(d, m, y);
		return A;
	}
}

int InputValidate::ReadInteger(const std::string& prompt)
{
	cout<<prompt;
	string str;
	cin>>str;
	return (atoi(str.c_str()));
}

Time InputValidate::ReadTime(const std::string& prompt)
{
	while (true)
	{
		cout<<prompt;
		cout<<"(24 hour Format: hh:mm): ";
		string temph, tempm;
		if(!getline(cin, temph,':'))
			continue;
		if(!getline(cin, tempm,'\n'))
			continue;
		if(temph.size()!=2||tempm.size()!=2)
			continue;
		//check that if all inputs of TIME are numbers (and not letters)
		if( (temph[0]<48 || temph[0]>57 || temph[1]<48 || temph[1]>57) || (tempm[0]<48 || tempm[0]>57 || tempm[1]<48 || tempm[1]>57) )
			continue;

		int h = atoi(temph.c_str());
		int m = atoi(tempm.c_str());
		//if "hour" input is more than 23 (then ask for input again)
		if(h>23)
			continue;
		//if "minute" input is more than 59 (then ask for input again)
		if(m>59)
			continue;

		Time A(h, m);
		return A;
	}
}

string InputValidate::ReadLine(const std::string& prompt)
{
	cout<<prompt;
	string a;
	getline(cin,a);
	return a;
}
