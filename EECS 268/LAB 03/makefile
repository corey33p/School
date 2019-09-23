Lab03: main.o Executive.o ShapeContainer.o Shape.o
	g++ main.o Executive.o ShapeContainer.o Shape.o -o Lab03.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

ShapeContainer.o: ShapeContainer.cpp ShapeContainer.h
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp ShapeContainer.h

Shape.o: Shape.cpp Shape.h
	g++ -std=c++11 -g -Wall -c Shape.cpp Shape.h

clean:
	rm -rf *.o *~ Lab03
