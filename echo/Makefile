# Makefile for Proxy Lab 
#
# You may modify this file any way you like (except for the handin
# rule). You instructor will type "make" on your specific Makefile to
# build your proxy from sources.

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

all: echo

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

echo.o: echo.c csapp.h
	$(CC) $(CFLAGS) -c echo.c

echo: echo.o echoserver.c echoclient.c csapp.o
	$(CC) $(CFLAGS) echoclient.c csapp.o -o echoclient $(LDFLAGS)
	$(CC) $(CFLAGS) echo.o echoserver.c csapp.o -o echoserver $(LDFLAGS)
	
clean:
	rm -f *~ *.o echo echoclient echoserver

