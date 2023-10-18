#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *line = NULL;

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
	FILE *file = NULL;
	stack_t *data_list = NULL;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * n);
	while (line_len != -1)
	{
		line_len = getdelim(&line, &n, '\n', file);
		apply_opcode(&data_list, line_num);
		line_num++;
	}
	free(line);
	fclose(file);
	/*free_list(data_list);*/
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
		{NULL, NULL},
	};
	char *word = "push" /*"get_word(1)"*/;

	if (word == NULL || *word == 0)
		return;

	for (i = 0; i < 2; i++)
	{
		if (strcmp(word, (arr[i]).opcode) == 0)
		{
			/*free(word);*/
			func = (arr[i]).f;
			func(list, line_num);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, word);
	/*free(word);*/
	free(line);
	/*free_list(list);*/
	exit(EXIT_FAILURE);
}

/**
 * push_op - pushes a new element to the stack
 * @list: doubly linked list with the data
 * @line_num: the current line in the .m file
 */
void push_op(stack_t **list, unsigned int line_num)
{
	if (list)
		printf("PUSH in line %u\n", line_num);
	else
		printf("PUSH CHECK\n");
}

/**
 * pall_op - prints elements of the stack
 * @list: doubly linked list with the data
 * @line_num: the current line in the .m file
 */
void pall_op(stack_t **list, unsigned int line_num)
{
	if (list)
		printf("PALL in line %u\n", line_num);
	else
		printf("PALL CHECK\n");
}
