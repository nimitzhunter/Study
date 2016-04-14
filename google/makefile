CC=clang++
CFLAGS=-Wall -std=c++11

all: matrix
program: matrix.o
program.o: matrix.cpp

clean:
	rm -f matrix matrix.o
run: program
	./program
