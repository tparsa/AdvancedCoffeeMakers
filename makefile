CPPFLAGS=-std=c++11	-Wall
CPPOFLAG=-c
CPPBINDFLAGS=-o ACM

all: utils.o main.o acm.o node.o
	g++ utils.o main.o acm.o node.o $(CPPFLAGS) $(CPPBINDFLAGS)

utils.o: utils/utils.hpp utils/utils.cpp
	g++ -c utils/utils.cpp $(CPPFLAGS) $(CPPOFLAGS)

acm.o: acm.hpp acm.cpp
	g++ -c acm.cpp $(CPPFLAGS) $(CPPOFLAGS)

node.o: node.hpp node.cpp
	g++ -c node.cpp $(CPPFLAGS) $(CPPOFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CPPFLAGS) $(CPPOFLAGS)

clean:
	touch ~lstID
	touch non.o
	touch ACM
	rm *.o && rm ACM

clear: clean