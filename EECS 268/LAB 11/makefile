L11: main.o Executive.o Heap.o Request.o EmptyHeap.o PriorityQueue.o EmptyPriorityQueue.o
	g++ -std=c++11 -g -Wall main.o Executive.o Heap.o Request.o EmptyHeap.o PriorityQueue.o EmptyPriorityQueue.o -o L11.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

Heap.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp Heap.h

Request.o: Request.h Request.cpp
	g++ -std=c++11 -g -Wall -c Request.cpp Request.h

EmptyHeap.o: EmptyHeap.h EmptyHeap.cpp
	g++ -std=c++11 -g -Wall -c EmptyHeap.cpp EmptyHeap.h

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -std=c++11 -g -Wall -c PriorityQueue.cpp PriorityQueue.h

EmptyPriorityQueue.o:  EmptyPriorityQueue.h EmptyPriorityQueue.cpp
	g++ -std=c++11 -g -Wall -c EmptyPriorityQueue.cpp EmptyPriorityQueue.h

clean:
	rm -rf *.o *~ L11
