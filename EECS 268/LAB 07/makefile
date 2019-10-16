L7: main.o Executive.o Matrix.o
	g++ -std=c++11 -g -Wall main.o Executive.o Field.o -o L7.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

Matrix.o: Field.h Field.cpp
	g++ -std=c++11 -g -Wall -c Field.cpp Field.h

clean:
	rm -rf *.o *~ L7
