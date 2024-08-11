#include "monty.h"

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
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, " \n");
                if (arg && is_digit(arg))
                    push(&stack, line_number, atoi(arg));
                else
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
}

