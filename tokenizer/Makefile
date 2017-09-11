all: test main

CFLAGS = -g -O2

main: main.o vToc.o
	cc -o main main.o vToc.o

test: test.o vToc.o
	cc -o test test.o vToc.o

vToc.o: vToc.c
	cc -c vToc.c

test.o: test.c vToc.h
	cc -c test.c

main.o: main.c vToc.h
	cc -c main.c

clean:
	rm -f *.o test main
