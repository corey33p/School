L4: main.o Executive.o Processor.o PrecondViolatedExcep.o Queue.o Stack.o Subprocess.o
	g++ -std=c++11 -g -Wall main.o Executive.o Processor.o PrecondViolatedExcep.o Queue.o Stack.o Subprocess.o -o L5.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

Processor.o: Processor.h Processor.cpp
	g++ -std=c++11 -g -Wall -c Processor.cpp Processor.h

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp PrecondViolatedExcep.h

Queue.o: Queue.h Queue.cpp
	g++ -std=c++11 -g -Wall -c Queue.cpp Queue.h
	
Stack.o: Stack.h Stack.cpp
	g++ -std=c++11 -g -Wall -c Stack.cpp Stack.h
		
Subprocess.o: Subprocess.h Subprocess.cpp
	g++ -std=c++11 -g -Wall -c Subprocess.cpp Subprocess.h

clean:
	rm -rf *.o *~ L4
