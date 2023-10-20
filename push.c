#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_node_stack - adds element at top of stack
 * @head: pointer to  first node of the list
 * @n: the number inside the new added  node
 * Return: pointer to the new node  if added
 */
int add_node_stack(stack_t **head, int n)
{
	stack_t *new = NULL;

	if (head)
		new = malloc(sizeof(stack_t));
	if (new)
	{
		new->n = n;
		new->prev = NULL;
		if (*head)
		{
			new->prev = (*head)->prev;
			(*head)->prev = new;
		}
		new->next = *head;
		*head = new;
		return (0);
	}

	return (1);
}

/**
 * add_node_queue - adds element at tip of queue
 * @head: pointer to  first node of the list
 * @n: the number inside the new added  node
 * Return: pointer to the new node  if added
 */
int add_node_queue(stack_t **head, int n)
{
	stack_t *move, *new = NULL;

	if (head)
		new = malloc(sizeof(stack_t));
	if (new)
	{
		move = *head;
		while (move && move->next)
			move = move->next;
		new->n = n;
		new->prev = move;
		new->next = NULL;
		if (move)
			move->next = new;
		else
			*head = new;
		return (0);
	}

	return (1);
}

/**
 * not_number - checks if atoi failed
 * @str: string of numbers 0 -> 9
 * Return: 1 if str not in 0 -> 9
 */
int not_number(char *str)
{
	if (str == NULL)
		return (1);

	if (*str == '-' || *str == '+')
		str++;

	do {
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	} while (*str);

	return (0);
}

/**
 * push_op - pushes new element to stack or queue
 * @list: doubly linked list with the data
 * @line_num: the current line in the .m file
 */
void push_op(stack_t **list, unsigned int line_num)
{
	char *word = get_word(2);
	int err, n = atoi(word);

	if (not_number(word))
	{
		free(word);
		syntax_error(1, list, line_num);
	}
	if (G.is_stack)
		err = add_node_stack(list, n);
	else
		err = add_node_queue(list, n);

	free(word);
	if (err)
	{
		free_list(list);
		malloc_error();
	}
}
