#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

global_t G;

/**
 * main - monty python
 * @ac: ac
 * @av: av
 * Return: zzero
 */
int main(int ac, char **av)
{
	ssize_t line_num = 1, line_len = 0;
	size_t n = 128;
	stack_t *list = NULL;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	G.file = fopen(av[1], "r");
	if (G.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	G.is_stack = 1;
	G.line = malloc(sizeof(char) * n);
	if (G.line == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(G.file);
		exit(EXIT_FAILURE);
	}
	while (line_len != -1)
	{
		line_len = getline(&(G.line), &n, G.file);
		if (line_len > 0)
			apply_opcode(&list, line_num);
		line_num++;
	}
	free(G.line);
	fclose(G.file);
	free_list(&list);
	return (EXIT_SUCCESS);
}

/**
 * apply_opcode - invokes the suitable op function for the op code
 * @list: doubly linked list with the data to pass it  to the func
 * @line_num: the current line in the .m file
 */
void apply_opcode(stack_t **list, unsigned int line_num)
{
	int i;
	void (*func)(stack_t **list, unsigned int line_num);
	instruction_t arr[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"swap", swap_op},
		{"pop", pop_op},
		{NULL, NULL},
	};
	char *word = get_word(1);

	if (word == NULL)
		return;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(word, (arr[i]).opcode) == 0)
		{
			free(word);
			func = (arr[i]).f;
			func(list, line_num);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, word);
	free(word);
	free(G.line);
	free_list(list);
	fclose(G.file);
	exit(EXIT_FAILURE);
}
