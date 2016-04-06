#include "Schedule.h"

using namespace std;

void Schedule::addToSchedule(Event ev)
{
	if(ev.getstartTime() > ev.getendTime())
	{
		cout<<endl<<"An event cannot END before it STARTS!"<<endl;
		cout<<"ENTRY NOT SAVED"<<endl<<endl;
		return;
	}
	if(ev.getstartTime() == ev.getendTime())
	{
		cout<<endl<<"An event cannot END at the same time it STARTS!"<<endl;
		cout<<"ENTRY NOT SAVED"<<endl<<endl;
		return;
	}

	for(int i=0; i<Events.size(); i++)
	{
		if( ev.geteventDate()==Events[i].geteventDate() )
		{
			if( !( ( ev.getendTime() < Events[i].getstartTime() )  || ( ev.getstartTime() > Events[i].getendTime() ) ) )
			{
				cout<<endl<<"Sorry, there is a clash with this event:"<<endl;
				Events[i].printEvent();
				cout<<endl<<"ENTRY NOT SAVED"<<endl<<endl;
				return;
			}
		}
	}

	int counter = 0;

	for(int i=0; i<Events.size(); i++)
	{
		if( ev.geteventDate() > Events[i].geteventDate() )
		{
			counter++;
		}
		else if( ev.geteventDate() == Events[i].geteventDate() )
		{
			if( ev.getstartTime() > Events[i].getstartTime() )
			{
				counter++;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	cout<<endl<<"ENTRY STORED"<<endl<<endl;
	Events.insert(Events.begin()+counter, ev);
}

void Schedule::printDaily()
{
	Date searchDate = InputValidate::ReadDate("ENTER DATE: ");

	int counter = 0;

	for(int i=0; i<Events.size(); i++)
	{
		if( searchDate==Events[i].geteventDate())
		{
			counter++;
			cout<<endl<<"Event "<<counter<<endl;
			Events[i].printEvent();
		}
	}

	if(counter == 0)
	{
		cout<<endl;
		cout<<"You have no events scheduled for ";
		searchDate.printDate();
		cout<<endl;
		return;
	}
	cout<<endl<<endl;
}

void Schedule::printMonthly()
{
	Date searchDate = InputValidate::ReadDate("ENTER DATE: ");

	int searchMonth = searchDate.getMonth();
	int searchYear = searchDate.getYear();

	int counter = 0;

	for(int i=0; i<Events.size(); i++)
	{
		if( searchMonth==Events[i].geteventDate().getMonth() && searchYear==Events[i].geteventDate().getYear())
		{
			counter++;
			cout<<endl<<"Event "<<counter<<endl;
			Events[i].printEvent();
		}
	}

	if(counter == 0)
	{
		cout<<endl;
		cout<<"You have no events scheduled for Month: "<<searchMonth<<" and Year: "<<searchYear<<endl;
		cout<<endl;
		return;
	}
	cout<<endl<<endl;
}

void Schedule::cancelEvent()
{
	Date cancelDate = InputValidate::ReadDate("ENTER DATE: ");

	int index = 0;
	int counter = 0;

	for(int i=0; i<Events.size(); i++)
	{
		if( cancelDate==Events[i].geteventDate())
		{
			if(counter == 0)
			{
				index = i;
			}
			counter++;
			cout<<endl<<"Event "<<counter<<endl;
			Events[i].printEvent();
		}
	}

	if(counter == 0)
	{
		cout<<endl;
		cout<<"You have no events scheduled for ";
		cancelDate.printDate();
		cout<<endl;
		return;
	}

	cout<<endl<<endl;

	int choice;

	do
	{
		cout<<endl;
		cout<<"Please choose the event to cancel (between 1 and "<<counter<<"): ";
		cin>>choice;
	}while(choice<1 && choice>counter);

	Events.erase(Events.begin()+choice+index-1);
}

void Schedule::searchSchedule()
{
	int matches = 0;

	string findName = InputValidate::ReadLine("ENTER NAME TO SEARCH: ");

	cout<<endl;
	for(int i=0; i<Events.size(); i++)
	{
		if( findString( Events[i].geteventName().c_str(), findName.c_str() ) )
		{
			matches++;
			cout<<"Event "<<matches<<endl;
			Events[i].printEvent();
		}
	}
	if(matches==0)
	{
		cout<<"No match found for \""<<findName<<"\"!"<<endl;
	}
}

bool Schedule::findString(const char* str1, const char* str2)
{
	int counter=0;
	int same=0;

	while( (*(str1+counter)!= '\0' ) )
	{
		if(*(str1+counter)==*(str2))
		{
			for(int i=0; *(str2+i)!='\0';i++)
			{
				if(*(str1+counter+i)==*(str2+i))
				{
					same=1;
				}
				else
				{
					same=0;
					break;
				}
			}
		}
		if(same==1)
		{
			return true;
		}
		counter++;
	}
	return false;
}

void Schedule::saveSchedule(ostream& fout)
{
	for(int i=0; i<Events.size(); i++)
	{
		Events[i].saveEvent(fout);
	}
}
