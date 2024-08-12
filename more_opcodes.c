#include "monty.h"

/**
* swap - Swaps the top two elements of the stack.
* @stack: Double pointer to the top of the stack.
* @line_number: The current line number in the bytecode file.
*
* Description: If the stack contains less than two elements, an error message
* is printed, and the program exits with EXIT_FAILURE status.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
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
* @stack: Double pointer to the top of the stack.
* @line_number: The current line number in the bytecode file.
*
* Description: If the stack contains less than two elements, an error message
* is printed, and the program exits with EXIT_FAILURE status.
* The result is stored in the second top element of the stack, and the top
* element is removed.
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n; /* Add the top two elements */
	pop(stack, line_number);           /* Remove the top element */
}

