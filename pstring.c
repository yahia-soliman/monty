#include "monty.h"
/**
 * pstr_op - prints the string starting at the top of the stack
 * followed by a new line.
 * @list: Head of the list
 * @line_num: line number
 */
void pstr_op(stack_t **list, unsigned int line_num)
{
	stack_t *move = *list;

	for (; move != NULL && move->n != 0 && line_num; move = move->next)
	{
		if (move->n < 1 || move->n > 127)
			break;
		putchar(move->n);
	}
	putchar('\n');
}

/**
 * pchar_op - prints the character at the TOS
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void pchar_op(stack_t **list, unsigned int line_num)
{
	int c;

	if (*list == NULL)
		syntax_error(12, list, line_num);
	c = (*list)->n;
	if (c > 127 || c < 0)
		syntax_error(11, list, line_num);

	putchar(c);
	putchar('\n');
}
