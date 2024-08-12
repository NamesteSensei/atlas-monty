#include "monty.h"

/**
 * main - Entry point for the Monty Interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    execute(argv[1]);

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
void handle_opcode(char *opcode, stack_t **stack,
                   unsigned int line_number, char *arg)
{
    if (strcmp(opcode, "push") == 0)
    {
        if (arg && is_digit(arg))
            push(stack, line_number, atoi(arg));
        else
            handle_error(line_number, "usage: push integer");
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)  /* Handle nop opcode */
    {
        nop(stack, line_number);
    }
    else
    {
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

    file = fopen(file_name, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \n");

        if (opcode && opcode[0] != '#')
        {
            char *arg = strtok(NULL, " \n");

            handle_opcode(opcode, &stack, line_number, arg);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
}
