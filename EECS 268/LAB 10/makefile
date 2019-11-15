L10: main.o Executive.o BinaryNode.o BinarySearchTree.o Pokemon.o
	g++ -std=c++11 -g -Wall main.o Executive.o BinaryNode.o BinarySearchTree.o Pokemon.o -o L10.o

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp Executive.h

BinaryNode.o: BinaryNode.h BinaryNode.cpp
	g++ -std=c++11 -g -Wall -c BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp BinarySearchTree.h

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp Pokemon.h

clean:
	rm -rf *.o *~ L10
