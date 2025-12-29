Drawing.o: Drawing.h Drawing.cpp List.h ListLinked.h Shape.h Circle.h Square.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

