#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

global_t G;

/**
 * main - monty python
 * @ac: give it 1 argument
 * @av: the argument a .m file
 * Return: zero if every thing is ok
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
		malloc_error();

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
	instruction_t arr[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"swap", swap_op},
		{"pop", pop_op},
		{"add", add_op},
		{"sub", sub_op},
		{"mul", mul_op},
		{"div", div_op},
		{"mod", mod_op},
		{"nop", nop_op},
		{"stack", queue_op},
		{"queue", queue_op},
		{NULL, NULL},
	};
	char *word = get_word(1);

	if (word == NULL)
		return;

	for (i = 0; (arr[i]).opcode != NULL; i++)
	{
		if (strcmp(word, (arr[i]).opcode) == 0)
		{
			free(word);
			(arr[i]).f(list, line_num);
			return;
		}
	}

	syntax_error(0, list, line_num);
	fprintf(stderr, "%s\n", word);
	free(word);
	exit(EXIT_FAILURE);
}
