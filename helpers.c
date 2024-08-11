#include "monty.h"

int is_digit(char *str)
{
    if (str == NULL || *str == '\0')
        return (0);

    if (*str == '-')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }

    return (1);
}

void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}

void handle_error(unsigned int line_number, const char *message)
{
    fprintf(stderr, "L%u: %s\n", line_number, message);
    exit(EXIT_FAILURE);
}

