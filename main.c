#include "monty.h"

stack_t *global_stack = NULL;

/**
 * execute - executes the opcode
 * @line: line from the file
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode in the file
 */
void execute(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode;
    char *arg;
    instruction_t instructions[] = {
        {"push", NULL},
        {"pall", pall},
        {NULL, NULL}
    };
    int i = 0;

    opcode = strtok(line, " \n");
    if (!opcode || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \n");
        push(stack, line_number, arg);
    }
    else
    {
        while (instructions[i].opcode)
        {
            if (strcmp(instructions[i].opcode, opcode) == 0)
            {
                instructions[i].f(stack, line_number);
                return;
            }
            i++;
        }
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exit with failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        execute(line, &global_stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(global_stack);
    return (0);
}

