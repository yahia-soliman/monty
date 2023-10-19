CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89

#make
all: clean monty

#make monty
monty:
	$(CC) $(CFLAGS) *.c -o monty

#make <n (0-15)>   will test the n task
%: ./mfiles/%.m
	cat $<
	./monty $<

#make clean
clean:
	rm monty
