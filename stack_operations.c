#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: The stack to pop from.
 * @line_number: The line number of the bytecode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: The stack to swap elements in.
 * @line_number: The line number of the bytecode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: The stack to add elements from.
 * @line_number: The line number of the bytecode.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - No operation.
 * @stack: The stack to do nothing to.
 * @line_number: The line number of the bytecode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

