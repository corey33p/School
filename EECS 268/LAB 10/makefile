L8: main.o Executive.o City.o
	g++ -std=c++11 -g -Wall main.o Executive.o City.o -o L8.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp City.h

clean:
	rm -rf *.o *~ L8
