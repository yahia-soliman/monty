#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _strspn -  Get length of a prefix substring
 * @s: Source sting
 * @accept: Accept dilmeters
 * Return: length of the substring or 0 if fails
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int length = 0;
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (accept[j] == s[i])
				return (length);
		}
		length++;
	}
	return (length);
}

/**
 * skip - Checks if the char is space or not
 * @c: The char to check
 * Return: 1 if match 0 if not
 */
int skip(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

/**
 * get_word - Get a single word from G.line
 * @n: Word number
 * Return: That word on sucess NULL if fails
 */
char *get_word(int n)
{
	char *move = G.line, *word = NULL;
	int i = 0, len = 0;

	/*skip all the spaces and taps*/
	for (; n > 0 && *move != '\0'; move++)
	{
		/*if the currnt char is not space or tap*/
		if (!skip(*move) && n--) /*skip word*/
			while (skip(*move) == 0 && *move != '\0' && n > 0)
				move++;
	}

	move--;
	len = _strspn(move, " \t\n#");

	if (len != 0) /*start malloc if len > 0 */
		word = malloc(sizeof(char) * (len + 1));
	if (len != 0 && word == NULL)
	{
		fclose(G.file);
		free(G.line);
		/*free_list(list);*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*start copying the buffer*/
	for (i = 0; i < len; i++)
		word[i] = move[i];

	if (word)
		word[i] = '\0';

	return (word);
}
