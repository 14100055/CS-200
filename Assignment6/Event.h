#ifndef _EVENT_H_
#define _EVENT_H_
#include "Time.h"
#include "Date.h"
#include<iostream>
#include<string>

using namespace std;

class Event
{
	public:
		Event(Date, Time, Time, string, string);
		void printEvent();
		void saveEvent(ostream& fout);
		Date geteventDate();
		Time getstartTime();
		Time getendTime();
		string geteventName();
	private:
		Date eventDate;
		Time startTime;
		Time endTime;
		string eventName;
		string eventLocation;
};

#endif
