CC = gcc
CFLAGS = -std=c99 -pthread

all: Lab6 threadSync

Lab6: Lab6.c
	$(CC) $(CFLAGS) Lab6.c -o Lab6

threadSync: threadSync.c
	$(CC) $(CFLAGS) threadSync.c -o threadSync

clean:
	rm -f Lab6 threadSync