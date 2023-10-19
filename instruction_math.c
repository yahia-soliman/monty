#include "monty.h"

/**
 * add_op - Adds the top two elements
 * and stored the result in the second top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void add_op(stack_t **list, unsigned int line_num)
{
	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(6, list, line_num);

	(*list)->next->n = ((*list)->n) + ((*list)->next->n);
	pop_op(list, line_num);
}

/**
 * sub_op - Subtracts the top element of the stack from the second top element
 * result is stored in the second top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void sub_op(stack_t **list, unsigned int line_num)
{
	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(7, list, line_num);

	(*list)->next->n = ((*list)->next->n) - ((*list)->n);
	pop_op(list, line_num);
}

/**
 * mul_op - Multiplies the second top element of
 * the stack with the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void mul_op(stack_t **list, unsigned int line_num)
{
	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(9, list, line_num);

	(*list)->next->n = ((*list)->next->n) * ((*list)->n);
	pop_op(list, line_num);
}

/**
 * div_op - Divides the second top element of the stack
 * by the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void div_op(stack_t **list, unsigned int line_num)
{
	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(8, list, line_num);
	else if ((*list)->n == 0)
		syntax_error(2, list, line_num);

	(*list)->next->n = ((*list)->next->n) / ((*list)->n);
	pop_op(list, line_num);
}

/**
 * mod_op - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void mod_op(stack_t **list, unsigned int line_num)
{
	if ((*list) == NULL || (*list)->next == NULL)
		syntax_error(10, list, line_num);
	else if ((*list)->n == 0)
		syntax_error(2, list, line_num);

	(*list)->next->n = ((*list)->next->n) % ((*list)->n);
	pop_op(list, line_num);
}
