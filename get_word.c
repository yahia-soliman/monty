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
 * get_word - Get a single word in a line
 * @n: Word number
 * @line: Line of words
 * Return: That word on sucess NULL if fails
 */
char *get_word(int n, char *line)
{
	char *move = line, *word = NULL;
	int i = 0, len = 0;

	for (; n > 0 && *move != '\0'; move++) /*skip all the spaces and taps*/
	{
		if (!skip(*move) && n--)							   /*if the currnt char is not space or tap*/
			while (skip(*move) == 0 && *move != '\0' && n > 0) /*skip word*/
				move++;
	}

	move--;
	len = _strspn(move, " \t");

	if (len != 0) /*start malloc if len > 0 */
		word = malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++) /*start copying the buffer*/
		word[i] = move[i];

	return (word);
}

int main(void)
{
	char arr[] = "push 3     anything after the instruction  is ignored   !!";
	char *word = NULL;

	word = get_word(17, arr);
	printf("%s\n", word);
	free(word);
}
