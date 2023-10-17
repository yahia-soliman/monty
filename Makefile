CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89

#make
all: monty

#make monty
monty: monty.h main.c
	$(CC) $(CFLAGS) *.c -o monty

#make <n (0-15)>   will test the n task
%: ./mfiles/%.m monty
	cat $<
	./monty $<

#make clean
clean:
	rm monty
