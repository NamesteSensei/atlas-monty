#include "monty.h"  /* Include the header file for function prototypes and definitions */

/**
* main - Entry point for the Monty Interpreter.
* @argc: Argument count.
* @argv: Argument vector.
*
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
*/
int main(int argc, char *argv[])
{
/* Check if the program is called with the correct number of arguments */
if (argc != 2)
{
/* Print an error message if the file name is not provided */
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

/* Execute the bytecode file */
execute(argv[1]);

/* Return success status */
return (EXIT_SUCCESS);
}

/**
* handle_opcode - Processes an opcode and performs the corresponding action.
* @opcode: The opcode to process.
* @stack: Double pointer to the top of the stack.
* @line_number: The current line number in the bytecode file.
* @arg: The argument for the opcode, if any.
*
* Description: This function processes the given opcode and performs the
* corresponding action on the stack. If the opcode is unknown, an error
* message is printed, and the program exits.
*/
void handle_opcode(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
/* Check if the opcode is "push" */
if (strcmp(opcode, "push") == 0)
{
/* Convert the argument to an integer and push it onto the stack */
if (arg && is_digit(arg))
push(stack, line_number, atoi(arg));
else
handle_error(line_number, "usage: push integer");
}
else if (strcmp(opcode, "pall") == 0)
{
/* Call the pall function to print all elements of the stack */
pall(stack, line_number);
}
else if (strcmp(opcode, "pint") == 0)
{
/* Call the pint function to print the top element of the stack */
pint(stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
/* Call the pop function to remove the top element of the stack */
pop(stack, line_number);
}
else if (strcmp(opcode, "swap") == 0)
{
/* Call the swap function to swap the top two elements of the stack */
swap(stack, line_number);
}
else if (strcmp(opcode, "add") == 0)
{
/* Call the add function to add the top two elements of the stack */
add(stack, line_number);
}
else
{
/* Print an error message if the opcode is unknown */
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}

/**
* execute - Executes the bytecodes in the file.
* @file_name: Name of the file to be executed.
*
* Description: This function opens the file, reads the bytecodes line by line,
* and processes each opcode. It handles errors like file opening failures,
* unknown instructions, and more.
*/
void execute(char *file_name)
{
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t read;
stack_t *stack = NULL;
unsigned int line_number = 0;

/* Open the bytecode file */
file = fopen(file_name, "r");
if (file == NULL)
{
/* Print an error message if the file cannot be opened */
fprintf(stderr, "Error: Can't open file %s\n", file_name);
exit(EXIT_FAILURE);
}

/* Read each line of the file */
while ((read = getline(&line, &len, file)) != -1)
{
line_number++;  /* Increment the line number */

/* Extract the opcode and argument from the line */
char *opcode = strtok(line, " \n");

if (opcode && opcode[0] != '#')
{
char *arg = strtok(NULL, " \n");
handle_opcode(opcode, &stack, line_number, arg);  /* Process the opcode */
}
}

free(line);         /* Free the memory allocated for the line */
fclose(file);       /* Close the file */
free_stack(stack);  /* Free the stack memory */
}

