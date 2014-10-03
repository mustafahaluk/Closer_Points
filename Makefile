all: main.o

main.o: main.cc
	g++ -c main.cc
	g++  main.o -o project1

clean:
	rm -rf *o  project1
