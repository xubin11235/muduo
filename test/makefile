all:test

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

test:test.o
	$(CC) $(LDFLAGS) -o $@ $^

test.o:test.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm test.o test
