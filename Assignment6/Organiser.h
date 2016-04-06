#ifndef _ORGANISER_H_
#define _ORGANISER_H_
#include "InputValidate.h"
#include "Schedule.h"
#include <fstream>

using namespace std;

class Organiser
{
	public:
		void DoAddCommand();
		void DoCancelCommand();
		void DoPrintCommand();
		void DoFindCommand();
		void DoHelpCommand();
		void CommandLoop();
		Organiser();
		~Organiser();
	private:
		Schedule sched;
};

#endif
