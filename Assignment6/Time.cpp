#include "Time.h"
Time::Time()
{} // constructor

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::setTime(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::printTime()
{
    cout << hours;
    cout << ":";
    cout<<((minutes<10)?"0":"") << minutes<<" hours"<<endl;
}

void Time::saveTime(ostream& fout)
{
    fout << hours;
    fout << ":";
    fout<<((minutes<10)?"0":"") << minutes<<",";
}

bool operator < (Time obj_a, Time obj_b)
{
	if(obj_a.hours==obj_b.hours)
	{
		if(obj_a.minutes<obj_b.minutes)
		{
			return true;
		}
	}
	else if(obj_a.hours<obj_b.hours)
	{
		return true;
	}
	return false;
}

bool operator > (Time obj_a, Time obj_b)
{
	if(obj_a.hours==obj_b.hours)
	{
		if(obj_a.minutes>obj_b.minutes)
		{
			return true;
		}
	}
	else if(obj_a.hours>obj_b.hours)
	{
		return true;
	}
	return false;
}

bool operator == (Time obj_a, Time obj_b)
{
	if(obj_a.hours==obj_b.hours)
	{
		return obj_a.minutes==obj_b.minutes;
	}
	return false;
}
