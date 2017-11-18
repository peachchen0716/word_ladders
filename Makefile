all: wordladder

wordladder: wordladder.o igraph.o
	g++ -o wordladder wordladder.o igraph.o

wordladder.o: wordladder.cpp igraph.h
	g++ -c -O2 wordladder.cpp

igraph.o: igraph.cpp igraph.h
	g++ -c -O2 igraph.cpp

clean:
	rm -f wordladder wordladder.o igraph.o
