#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include "Time.h"
using namespace std;
class Date
{
	private:
		int day;
		int month;
		int year;

	public:
		Date(int day, int month, int year);
		Date() {}
		void printDate();
		void saveDate(ostream& fout);
		void setDate(int d, int m, int y); //function to change a date object
		int getMonth();
		int getYear();
        friend bool operator < (Date obj_a, Date obj_b);
		friend bool operator > (Date obj_a, Date obj_b);
		friend bool operator == (Date obj_a, Date obj_b);
		/* date is less if it came before another date*/
};

#endif /* _DATE_H_ */
