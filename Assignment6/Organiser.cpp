#include "Organiser.h"

Organiser::~Organiser()
{
	ofstream fout;
	fout.open("MyOrganiser.csv");
	if(fout.fail( ) )
	{
		cout << "Error. Could not save to file.\n\n\n";
	}
	else
	{
		sched.saveSchedule(fout);
		fout.close();
	}
}

Organiser::Organiser()
{
	ifstream fin;
	fin.open("MyOrganiser.csv");
	if(fin.fail( ) )
	{
		cout << "Your Organiser is currently empty.\n\n\n";
	}
	else
	{
		string day, month, year;
		string startHour, startMin, endHour, endMin;
		string name, location;
		Date date;
		Time startTime;
		Time endTime;

		getline(fin, day, '/');
		getline(fin, month, '/');
		getline(fin, year, ',');
		getline(fin, startHour, ':');
		getline(fin, startMin, ',');
		getline(fin, endHour, ':');
		getline(fin, endMin, ',');
		getline(fin, name, ',');
		getline(fin, location, '\n');

		while(!fin.eof())
		{
			date.setDate( atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str()) );
			startTime.setTime( atoi(startHour.c_str()), atoi(startMin.c_str()) );
			endTime.setTime( atoi(endHour.c_str()), atoi(endMin.c_str()) );

			Event inputEvent(date, startTime, endTime, name, location);
			sched.addToSchedule(inputEvent);

			getline(fin, day, '/');
			getline(fin, month, '/');
			getline(fin, year, ',');
			getline(fin, startHour, ':');
			getline(fin, startMin, ',');
			getline(fin, endHour, ':');
			getline(fin, endMin, ',');
			getline(fin, name, ',');
			getline(fin, location, '\n');
		}
	}
	fin.close();
}

void Organiser::DoPrintCommand()
{
	string opt;
	int option=0;
	do
	{
		cout<<endl;
		cout<<"1) Daily Schedule"<<endl;
		cout<<"2) Monthly Schedule"<<endl;
		cout<<endl<<"Choose: ";

		getline(cin, opt);
		option = atoi(opt.c_str());

			if(opt=="1")
				sched.printDaily();
			else if(opt=="2")
				sched.printMonthly();
			else
				cout << endl << "**** Invalid command, try again ****" << endl << endl;
	}while( ( option!=1 ) && ( option!=2 ) );
}

void Organiser::DoCancelCommand()
{
	sched.cancelEvent();
}

void Organiser::DoAddCommand()
{
	cout<<endl;
	Date eventDate = InputValidate::ReadDate("DATE ");
	Time startTime = InputValidate::ReadTime("START TIME ");
	Time endTime = InputValidate::ReadTime("END TIME ");
	string eventName = InputValidate::ReadLine("EVENT NAME: ");
	string eventLocation = InputValidate::ReadLine("LOCATION: ");

	Event event(eventDate, startTime, endTime, eventName, eventLocation);
	sched.addToSchedule(event);
}

void Organiser::DoFindCommand()
{
	sched.searchSchedule();
}

void Organiser::CommandLoop()
{
	cout << endl << endl;
	cout << "******************************************" << endl;
	cout << "****** Welcome to the C++ ORGANIZER ******" << endl;
	cout << "**** The key to your organized future ****" << endl;
	cout << "******************************************" << endl;
	cout << endl << endl;

	string userInput;
	char userChoice;
	while((userChoice != 'q') && (userChoice != 'Q'))
	{
		while((userInput = InputValidate::ReadLine("Enter Choice or ? for help: ")) == "");
		userChoice = userInput.at(0);

		switch(userChoice)
		{
			case 'f':
			case 'F':
				DoFindCommand();
				break;
			case 'a':
			case 'A':
				DoAddCommand();
				break;
			case 'p':
			case 'P':
				DoPrintCommand();
				break;
			case 'c':
			case 'C':
				DoCancelCommand();
				break;
			case 'h':
			case 'H':
			case '?':
				DoHelpCommand();
				break;
			case 'q':
			case 'Q':
				break;
			default:
				cout << endl << "**** Invalid command, try again ****" << endl << endl;
		}
	}
	cout << endl << "Goodbye!" << endl << endl;
}

void Organiser::DoHelpCommand()
{
	cout << endl;
	cout << "Valid commands are:" << endl;
	cout <<	"    P/Print          print schedule for day" << endl;
	cout <<	"    A/Add            add a new event" << endl;
	cout <<	"    C/Cancel         cancel an already scheduled event" << endl;
	cout <<	"    F/Find           find events by phrase" << endl;
	cout <<	"    Q/Quit           quit" << endl;
	cout << "    H/Help           this help menu" << endl;
	cout << endl;
}
