#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_
#include "InputValidate.h"
#include <fstream>
#include <vector>

using namespace std;

class Schedule
{
	public:
		void addToSchedule(Event);
		void printDaily();
		void printMonthly();
		void cancelEvent();
		void searchSchedule();
		bool findString(const char* str1, const char* str2);
		void saveSchedule(ostream& fout);
		Schedule(){};
	private:
		vector <Event> Events;
};

#endif
