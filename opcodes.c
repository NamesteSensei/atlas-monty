#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 * @n: The integer to push onto the stack.
 *
 * Description: Adds a new element to the top of the stack.
 * If memory allocation fails, the function prints an error
 * message and exits the program.
 */
void push(stack_t **stack, unsigned int line_number, int n)
{
	(void)line_number;  /* Suppress unused parameter warning */
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 *
 * Description: Prints all the values in the stack, starting from the top.
 * If the stack is empty, nothing is printed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;  /* Suppress unused parameter warning */
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

