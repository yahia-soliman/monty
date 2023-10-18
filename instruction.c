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
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		fclose(G.file);
		exit(EXIT_FAILURE);
	}

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
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(G.file);
		exit(EXIT_FAILURE);
	}

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
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(G.file);
		free_list(list);
		exit(EXIT_FAILURE);
	}

	temp = (*list)->n;
	(*list)->n = (*list)->next->n;
	(*list)->next->n = temp;
}
