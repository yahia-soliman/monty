#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * syntax_error - prints error messages
 * @idx: the index of the needed  error
 * @list: the list to free or NULL
 * @line_n: number of the current  line
 */
void syntax_error(int idx, stack_t **list, unsigned int line_n)
{
	char *sl, *sr, *err[] = {
		"unknown instruction ",
		"usage: push integer\n",
		"division by zero\n",
		"pint, stack empty\n",
		"pop an empty stack\n",
		"swap",
		"add",
		"sub",
		"div",
		"mul",
		"mod",
		"pchar, value out of range\n",
		"pchar, stack empty\n",
		NULL
	};

	sl = sr = "";
	if (idx > 2)
		sl = "can't ";
	if (idx > 4 && idx < 11)
		sr = ", stack too short\n";

	fprintf(stderr, "L%u: %s%s%s", line_n, sl, err[idx], sr);

	free(G.line);
	fclose(G.file);
	free_list(list);
	if (idx > 0)
		exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc failed
 */
void malloc_error(void)
{
	free(G.line);
	fclose(G.file);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
