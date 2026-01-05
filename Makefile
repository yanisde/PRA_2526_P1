bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h Node.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.h Point2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.cpp Point2D.cpp

bin/testCircle: testCircle.cpp Circle.h Circle.cpp Shape.h Shape.cpp Point2D.h Point2D.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.cpp Circle.cpp Shape.cpp Point2D.cpp

bin/testRectangle: testRectangle.cpp Rectangle.h Rectangle.cpp Shape.h Shape.cpp Point2D.h Point2D.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.cpp Shape.cpp Point2D.cpp

bin/testSquare: testSquare.cpp Square.h Square.cpp Rectangle.h Rectangle.cpp Shape.h Shape.cpp Point2D.h Point2D.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.cpp Square.cpp Rectangle.cpp Shape.cpp Point2D.cpp
Drawing.o: Drawing.h Drawing.cpp List.h ListLinked.h Shape.h Circle.h Square.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

