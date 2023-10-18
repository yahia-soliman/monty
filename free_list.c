#include "monty.h"
#include <stdlib.h>
/**
 * free_list - frees data list
 * @h: pointer to the first node
 */
void free_list(stack_t **h)
{
	stack_t *move, *head = *h;

	while (head && head->prev)
		head = head->prev;

	while (head)
	{
		move = head->next;
		free(head);
		head = move;
	}
	*h = NULL;
}
