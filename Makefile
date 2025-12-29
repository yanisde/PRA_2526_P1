Square.o: Square.h Square.cpp Rectangle.h Point2D.h Shape.h
	g++ -c Square.cpp

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

