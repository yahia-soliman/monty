#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>

/**
 * struct global_s - I just use one global variable
 * @file: file pointer to close it before any exit
 * @line: the current line in the file to read  it
 * @is_stack: specifies mode of the data structure
 */
typedef struct global_s
{
	FILE *file;
	char *line;
	int is_stack;
} global_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t G;
char *get_word(int word_num);
void free_list(stack_t **list);
void apply_opcode(stack_t **list, unsigned int line_num);
void push_op(stack_t **list, unsigned int line_num);
void pall_op(stack_t **list, unsigned int line_num);
void pint_op(stack_t **list, unsigned int line_num);
void pop_op(stack_t **list, unsigned int line_num);
void swap_op(stack_t **list, unsigned int line_num);
void add_op(stack_t **list, unsigned int line_num);
void sub_op(stack_t **list, unsigned int line_num);
void mul_op(stack_t **list, unsigned int line_num);
void div_op(stack_t **list, unsigned int line_num);
void mod_op(stack_t **list, unsigned int line_num);
#endif/*__MONTY__*/
