#My makefile 1 for the first imp.

CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -std=c++03 -g -Iincludes

#*****************Program generation*****************

all: bin/connectN

#******************Objects**********************

obj/matrix.o : includes/matrix.h src/matrix.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/matrix.o src/matrix.cpp

obj/board.o : includes/board.h src/board.cpp includes/matrix.h
	$(CXX) -c $(CXXFLAGS) -o obj/board.o src/board.cpp

obj/player.o : includes/player.h src/player.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/player.o src/player.cpp

obj/gameIO.o:  includes/gameIO.h src/gameIO.cpp includes/player.h includes/board.h
	$(CXX) -c $(CXXFLAGS) -o obj/gameIO.o src/gameIO.cpp

obj/main.o :  src/main.cpp includes/board.h includes/matrix.h includes/gameIO.h includes/player.h
	$(CXX) -c $(CXXFLAGS) -o obj/main.o src/main.cpp


#******************Exec file generation*************
bin/connectN: obj/main.o obj/board.o obj/gameIO.o obj/player.o obj/matrix.o
	$(CXX) -o bin/connectN obj/main.o obj/board.o obj/gameIO.o obj/player.o obj/matrix.o


#************************Cleaning******************
clean:
	echo "Cleaning..."
	rm obj/*.o

mrproper: clean
	rm bin/*
