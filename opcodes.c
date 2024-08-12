#include "monty.h"

/**
 * nop - Dosent't do anything.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 *
 * Description: The nop opcode does nothing. It's just a placeholder.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Suppress unused variable warning */
	(void)line_number; /* Suppress unused variable warning */
}

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
	stack_t *new_node;

	(void)line_number;  /* Suppress unused parameter warning */

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
	stack_t *current = *stack;

	(void)line_number;  /* Suppress unused parameter warning */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 *
 * Description: If the stack is empty, an error message is printed, and the
 * program exits with EXIT_FAILURE status.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the bytecode file.
 *
 * Description: If the stack is empty, an error message is printed, and the
 * program exits with EXIT_FAILURE status.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

