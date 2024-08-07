#include "monty.h"
#include <ctype.h>
#include <limits.h>  /* Add this line to include INT_MAX and INT_MIN */

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the file
 * @arg: argument to push (integer)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;
    char *endptr;
    long n;

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = strtol(arg, &endptr, 10);

    /* Check if the conversion was successful */
    if (*endptr != '\0' || endptr == arg || n > INT_MAX || n < INT_MIN)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = (int)n;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

