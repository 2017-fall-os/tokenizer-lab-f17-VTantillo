all: test main newToke

CFLAGS = -g -O2

newToke: newToke.o vToke.o
	cc -o newToke newToke.o vToke.o

main: main.o vToc.o
	cc -o main main.o vToc.o

test: test.o vToc.o
	cc -o test test.o vToc.o

newToke.o: newToke.c vToke.h
	cc -c newToke.c

vToke.o: vToke.c
	cc -c vToke.c

vToc.o: vToc.c
	cc -c vToc.c

test.o: test.c vToc.h
	cc -c test.c

main.o: main.c vToc.h
	cc -c main.c

clean:
	rm -f *.o test main newToke
