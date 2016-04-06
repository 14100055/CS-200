Assignment6: main.o Date.o InputValidate.o Organiser.o Time.o Event.o Schedule.o
	g++ -o Assignment6 main.o Date.o InputValidate.o Organiser.o Time.o Event.o Schedule.o

main.o: main.cpp Organiser.h InputValidate.h Date.h Time.h Event.h Schedule.h
	g++ -c main.cpp

Organiser.o: Organiser.cpp Organiser.h InputValidate.h Date.h Time.h Event.h Schedule.h
	g++ -c Organiser.cpp

InputValidate.o: InputValidate.cpp InputValidate.h Date.h Time.h Event.h Schedule.h
	g++ -c InputValidate.cpp

Schedule.o: Schedule.cpp Schedule.h
	g++ -c Schedule.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

Date.o: Date.h Date.cpp
	g++ -c Date.cpp

Time.o: Time.h Time.cpp
	g++ -c Time.cpp

clean:
	rm *.o Assignment6
