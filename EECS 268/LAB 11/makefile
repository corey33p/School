L10: main.o Executive.o Heap.o Request.o
	g++ -std=c++11 -g -Wall main.o Executive.o Heap.o Request.o -o L11.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

BinaryNode.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp Heap.h

Request.o: Request.h Request.cpp
	g++ -std=c++11 -g -Wall -c Request.cpp Request.h

clean:
	rm -rf *.o *~ L11
