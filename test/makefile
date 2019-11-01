all:link

CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LDFLAGS=-pthread

link:link.o
	$(CC) $(LDFLAGS) -o $@ $^

link.o:link.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $^


.PHONY:
	clean

clean:
	rm *.o link
