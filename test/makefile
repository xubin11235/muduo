all:sort

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

sort:sort.o
	$(CC) $(LDFLAGS) -o $@ $^

sort.o:sort.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm *.o sort
