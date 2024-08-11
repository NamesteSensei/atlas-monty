#include <ctype.h>  /* Include for isdigit function */
#include "monty.h"

/**
 * main - Entry point for the Monty Interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
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
 * execute - Executes the bytecodes in the file
 * @file_name: Name of the file to be executed
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
        if (opcode && opcode[0] != '#') /* Ignore comments and blank lines */
        {
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, " \n");
                if (arg && is_digit(arg))
                    push(&stack, line_number, atoi(arg));
                else
                    handle_error(line_number, "usage: push integer");
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else
            {
                handle_error(line_number, "unknown instruction");
            }
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
}

