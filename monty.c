#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

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

    /* Process each line of the file */
    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Handle opcodes here (to be implemented) */
    }

    free(line);
    fclose(file);
    return 0;
}

