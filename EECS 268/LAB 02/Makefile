Lab02: main.o DictEntry.o Employee.o Executive.o
	g++ main.o DictEntry.o Employee.o Executive.o -o Lab02.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DictEntry.o: DictEntry.cpp DictEntry.h
	g++ -std=c++11 -g -Wall -c DictEntry.cpp DictEntry.h

Employee.o: Employee.cpp Employee.h
	g++ -std=c++11 -g -Wall -c Employee.cpp Employee.h

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

#Map.o: map.h
#	g++ -std=c++11 -g -Wall -c Map.h

clean:
	rm -rf *.o *~ Lab02
