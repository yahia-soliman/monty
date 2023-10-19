#include "monty.h"

/**
 * add_op - Adds the top two elements and stored the result in the second top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void add_op(stack_t **list, unsigned int line_num)
{
    if ((*list) == NULL || (*list)->next == NULL)
        printf("hello");
    /*Yo yahia handle this error with the messg "L<line_number>: can't sub, stack too short"*/

    (*list)->next->n = ((*list)->n) + ((*list)->next->n);
    pop_op(list, line_num);
}

/**
 * sub_op - Subtracts the top element of the stack from the second top element
 * result is stored in the second top element of the stack, and the top element is removed
 * @list: Head of the list
 * @line_num: Line number
 */
void sub_op(stack_t **list, unsigned int line_num)
{
    if ((*list) == NULL || (*list)->next == NULL)
        printf("erro");
    /* Yo yahia handle this error with the messg "L<line_number>: can't sub, stack too short"*/

    (*list)->next->n = ((*list)->n) - ((*list)->next->n);
    pop_op(list, line_num);
}

/**
 * mul_op - Multiplies the second top element of the stack with the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void mul_op(stack_t **list, unsigned int line_num)
{
    if ((*list) == NULL || (*list)->next == NULL)
        printf("erro");
    /*Yo yahia handle this error with the messg "L<line_number>: can't mul, stack too short"*/

    (*list)->next->n = ((*list)->next->n) * ((*list)->n);
    pop_op(list, line_num);
}

/**
 * div_op - Divides the second top element of the stack by the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void div_op(stack_t **list, unsigned int line_num)
{
    if ((*list) == NULL || (*list)->next == NULL || (*list)->n == 0)
        printf("erro");
    /*Yo yahia handle this error with the messg "L<line_number>: can't div, stack too short"*/
    /*and if the user trying to div by 0 handel this error L<line_number>: division by zero*/

    (*list)->next->n = ((*list)->next->n) / ((*list)->n);
    pop_op(list, line_num);
}

/**
 * mod_op - Computes the rest of the division of the second top element of the stack by the top element of the stack.
 * @list: Head of the list
 * @line_num: Line number
 */
void div_op(stack_t **list, unsigned int line_num)
{
    if ((*list) == NULL || (*list)->next == NULL || (*list)->n == 0)
        printf("erro");
    /*Yo yahia handle this error with the messg "L<line_number>: can't mod, stack too short"*/
    /*and if the user trying to div by 0 handel this error L<line_number>: division by zero*/

    (*list)->next->n = ((*list)->next->n) % ((*list)->n);
    pop_op(list, line_num);
}
