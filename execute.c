#include "monty.h"

/**
 * execute - Executes a Monty opcode
 * @line: Line containing the opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 */
void execute(char *line, stack_t **stack, unsigned int line_number)
{
    char *opcode, *arg;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    unsigned int i;

    opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
        return;

    arg = strtok(NULL, " \t\n");

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number, arg);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

