#include "Event.h"

Event::Event(Date eDate, Time sTime, Time eTime, string name, string location)
{
	eventDate = eDate;
	startTime = sTime;
	endTime = eTime;
	eventName = name;
	eventLocation = location;
}

void Event::printEvent()
{
	cout<<"===================================="<<endl;
	cout<<"Date:       ";
	eventDate.printDate();
	cout<<"Start:      ";
	startTime.printTime();
	cout<<"End:        ";
	endTime.printTime();
	cout<<"Event name: "<<eventName<<endl;
	cout<<"Location:   "<<eventLocation<<endl;
	cout<<"===================================="<<endl;
}

void Event::saveEvent(ostream& fout)
{
	eventDate.saveDate(fout);
	startTime.saveTime(fout);
	endTime.saveTime(fout);
	fout<<eventName<<",";
	fout<<eventLocation<<"\n";
}

Date Event::geteventDate()
{
	return eventDate;
}

Time Event::getstartTime()
{
	return startTime;
}

Time Event::getendTime()
{
	return endTime;
}

string Event::geteventName()
{
	return eventName;
}
