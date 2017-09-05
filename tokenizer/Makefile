all: test

CFLAGS = -g -O2

test: test.o vToc.o
	cc -o test test.o vToc.o

clean:
	rm -f *.o test
