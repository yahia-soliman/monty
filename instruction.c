#include "monty.h"
#include <stdlib.h>

/**
 * pall_op - Prints all the values on the stack
 *           starting from the top of the stack
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void pall_op(stack_t **list, unsigned int line_num)
{
	stack_t *move = *list;

	for (move = *list; move != NULL && line_num; move = move->next)
		printf("%d\n", move->n);
}

/**
 * pint_op - Prints the value at the top of the stack, followed by a new line
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void pint_op(stack_t **list, unsigned int line_num)
{
	if (*list == NULL)
		syntax_error(3, list, line_num);

	printf("%d\n", (*list)->n);
}

/**
 * pop_op - Removes the top element of the stack
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void pop_op(stack_t **list, unsigned int line_num)
{
	stack_t *Free = (*list);

	if (*list == NULL)
		syntax_error(4, list, line_num);

	(*list) = Free->next;
	if (*list != NULL)
		(*list)->prev = NULL;
	free(Free);
}
/**
 * swap_op - Swaps the top two elements of the stack.
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void swap_op(stack_t **list, unsigned int line_num)
{
	int temp;

	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(5, list, line_num);

	temp = (*list)->n;
	(*list)->n = (*list)->next->n;
	(*list)->next->n = temp;
}
