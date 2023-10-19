#include "monty.h"
/**
 * queue_op - changes the data flow to FIFO
 * @ls: unused (linked list of data)
 * @ln: unused (number of current line)
 */
void queue_op(stack_t **ls, unsigned int ln)
{
	G.is_stack = 0;
	if (ln || ls)
		return;
}

/**
 * stack_op - changes the data flow to LIFO
 * @ls: unused (doubly linked list of data)
 * @ln: unused (number of the current line)
 */
void stack_op(stack_t **ls, unsigned int ln)
{
	G.is_stack = 1;
	if (ln || ls)
		return;
}

/**
 * nop_op - nothing, just a useless opcode
 * @ls: unused (doubly linked list of data)
 * @ln: unused (number of the current line)
 */
void nop_op(stack_t **ls, unsigned int ln)
{
	if (ln || ls)
		ln = 69;
}
