CC = gcc
CFLAGS = -Wall -pthread

all: threadHello_step1 threadHelloFixed_step1_Fixed

threadHello_step1: threadHello_step1.c
	$(CC) $(CFLAGS) -o threadHello_step1 threadHello_step1.c

threadHelloFixed_step1_Fixed: threadHelloFixed_step1_Fixed.c
	$(CC) $(CFLAGS) -o threadHelloFixed_step1_Fixed threadHelloFixed_step1_Fixed.c

clean:
	rm -f threadHello_step1 threadHelloFixed_step1_Fixed
