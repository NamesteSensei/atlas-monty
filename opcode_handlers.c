#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: The stack to push to.
 * @line_number: The line number of the bytecode.
 * @n: The integer to push.
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
    stack_t *new_node;

    (void)line_number; /* Unused in this simple implementation */

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: The stack to print.
 * @line_number: The line number of the bytecode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; /* Unused in this simple implementation */

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

