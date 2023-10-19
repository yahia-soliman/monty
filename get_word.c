#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * skip - Checks if the char is space or not
 * @c: The char to check
 * Return: 1 if match 0 if not
 */
int skip(char c)
{
	return (c == ' ' || c == '\t');
}

/**
 * at_end - Checks if c is the end of the code
 * @c: The char to check
 * Return: 1 if match 0 if not
 */
int at_end(char c)
{
	return (c == '\0' || c == '\n' || c == '#');
}

/**
 * get_word - Get a single word from G.line
 * @n: Word number
 * Return: That word on sucess NULL if fails
 */
char *get_word(int n)
{
	char *move = G.line, *word = NULL;
	int i = 0;

	/*find the first char of the word and its length*/
	while (!at_end(*move) && n--)
	{
		/*first: skip spaces*/
		while (skip(*move))
			move++;
		/*then: find the end of the word*/
		for (i = 0; !at_end(move[i]) && !skip(move[i]); i++)
			;
		/* if this is not the wanted word start again after it */
		if (n > 0)
			move += i;
	}

	if (i == 0)
		return (NULL);

	word = malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		malloc_error();

	/*start copying the buffer*/
	word[i] = '\0';
	while (i--)
		word[i] = move[i];

	return (word);
}
