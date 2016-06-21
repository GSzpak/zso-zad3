TARGET: ccp

CC = gcc
CFLAGS = -Wall -pedantic

ccp: ccp.c
	gcc -Wall -pedantic $^ -o $@

clean:
	rm -f ccp *~ *.bak
