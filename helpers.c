#include "monty.h"

/**
 * is_digit - Checks if a string consists only of digits.
 * @str: The string to check.
 *
 * Return: 1 if the string contains only digits, 0 otherwise.
 */
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

/**
 * free_stack - Frees a stack.
 * @stack: The stack to be freed.
 *
 * Description: Frees a doubly linked list stack_t.
 */
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

/**
 * handle_error - Prints an error message and exits the program.
 * @line_number: The line number where the error occurred.
 * @message: The error message to print.
 *
 * Description: This function prints an error message to stderr and
 * exits the program with EXIT_FAILURE status.
 */
void handle_error(unsigned int line_number, const char *message)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}

