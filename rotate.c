#include "monty.h"
/**
 * rotl_op - brings the top of the stack to the bottom
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void rotl_op(stack_t **list, unsigned int line_num)
{
	stack_t *move = *list;

	if ((*list) == NULL || (*list)->next == NULL || !line_num)
		return;

	while (move->next != NULL)
		move = move->next;

	move->next = (*list);
	*list = (*list)->next;
	(*list)->prev->next = NULL;
	(*list)->prev->prev = move;
	(*list)->prev = NULL;
}

/**
 * rotr_op - brings the bottom of the stack to the top
 * @list: Head of the stack/queue
 * @line_num: Line number of the instruction
 */
void rotr_op(stack_t **list, unsigned int line_num)
{
	stack_t *move = *list;
	int tos = line_num;

	if (move == NULL || move->next == NULL)
		return;

	tos = move->n;
	do {
		move = move->next;
		move->prev->n = move->n;
	} while (move->next);

	move->n = tos;
}
