CPPFLAGS=-std=c++11 -g -O3
EXECUTABLE=prog

all: Main.o
	g++ Main.o -o $(EXECUTABLE)

Main.o: Main.cpp LinkedList.h Node.h
	g++ $(CPPFLAGS) -c Main.cpp

clean: 
	rm -f *.o
	rm -f $(EXECUTABLE)