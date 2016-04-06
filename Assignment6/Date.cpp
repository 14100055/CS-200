#include "Date.h"

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
	year = y;
}

void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::printDate()
{
    cout << ((day<10)?"0":"") << day<<" / ";
    cout<<((month<10)?"0":"") << month;
    cout << " / " << year<<endl;
}

void Date::saveDate(ostream& fout)
{
    fout << ((day<10)?"0":"") << day<<"/";
    fout<<((month<10)?"0":"") << month;
    fout << "/" << year<<",";
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

bool operator < (Date obj_a, Date obj_b)
{
	if(obj_a.year==obj_b.year)
	{
		if(obj_a.month==obj_b.month)
		{
			if(obj_a.day<obj_b.day)
			{
				return true;
			}
		}
		else if(obj_a.month<obj_b.month)
		{
			return true;
		}
	}
	else if(obj_a.year<obj_b.year)
	{
		return true;
	}

	return false;
}

bool operator > (Date obj_a, Date obj_b)
{
	if(obj_a.year==obj_b.year)
	{
		if(obj_a.month==obj_b.month)
		{
			if(obj_a.day>obj_b.day)
			{
				return true;
			}
		}
		else if(obj_a.month>obj_b.month)
		{
			return true;
		}
	}
	else if(obj_a.year>obj_b.year)
	{
		return true;
	}

	return false;
}

bool operator == (Date obj_a, Date obj_b)
{
	if(obj_a.year==obj_b.year)
	{
		if(obj_a.month==obj_b.month)
		{
			if(obj_a.day==obj_b.day)
			{
				return true;
			}
		}
	}
	return false;
}
