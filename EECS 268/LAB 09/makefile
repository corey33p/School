L9: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o L9.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

clean:
	rm -rf *.o *~ L9
