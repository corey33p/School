L4: main.o Executive.o LinkedList.o PrecondViolatedExcep.o Student.o
	g++ -std=c++11 -g -Wall main.o Executive.o LinkedList.o PrecondViolatedExcep.o Student.o -o L4.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

ShapeContainer.o: LinkedList.o
	g++ -std=c++11 -g -Wall -c LinkedList.cpp LinkedList.h

Shape.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c Shape.cpp Shape.h

Student.o: Student.h
	g++ -std=c++11 -g -Wall -c Student.cpp SLNode.h

clean:
	rm -rf *.o *~ L4
