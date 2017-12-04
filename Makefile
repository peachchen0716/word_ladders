CC = g++
OPTION = -c -O2 -std=c++11

all: wordladder

wordladder: wordladder.o igraph.o
	$(CC) -o wordladder wordladder.o igraph.o

wordladder.o: wordladder.cpp igraph.h
	$(CC) $(OPTION) wordladder.cpp

igraph.o: igraph.cpp igraph.h
	$(CC) $(OPTION) igraph.cpp

clean:
	rm -f wordladder wordladder.o igraph.o
