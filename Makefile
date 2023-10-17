CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89


all: monty

monty: monty.h main.c
	$(CC) $(CFLAGS) *.c -o monty

clean:
	rm monty
