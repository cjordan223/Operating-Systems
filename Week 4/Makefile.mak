# Conner Jordan
# CST 334
# 7/18/23
# Makefile for Lab 4

all: fifo

fifo: fifo.c queue.o node.o
	gcc -o fifo fifo.c queue.o node.o

queue.o: queue.c queue.h node.h
	gcc -c queue.c

node.o: node.c node.h
	gcc -c node.c

clean:
	rm -f *.o fifo