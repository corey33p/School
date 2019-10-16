L6: main.o Executive.o Matrix.o
	g++ -std=c++11 -g -Wall main.o Executive.o Matrix.o -o L6.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

Matrix.o: Matrix.h Matrix.cpp
	g++ -std=c++11 -g -Wall -c Matrix.cpp Matrix.h

clean:
	rm -rf *.o *~ L6
