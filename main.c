#include "monty.h"    /* Include the header file that contains function prototypes and definitions */
#include <stdio.h>    /* Include standard input/output functions */
#include <stdlib.h>   /* Include standard library functions, including malloc and exit */

/**
 * main - entry point of the Monty interpreter
 * @argc: argument count (number of command-line arguments)
 * @argv: argument vector (array of command-line argument strings)
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;    /* File pointer to handle the Monty bytecode file */
    char *line = NULL;    /* Pointer to hold each line read from the file */
    size_t len = 0;    /* Variable to hold the length of each line */
    ssize_t read;    /* Variable to store the number of characters read */

    /* Check if the number of arguments is exactly 2 */
    if (argc != 2)
    {
        /* Print error message if the argument count is incorrect */
        fprintf(stderr, "USAGE: monty file\n");
        /* Exit the program with status EXIT_FAILURE to indicate an error */
        exit(EXIT_FAILURE);
    }

    /* Open the file provided as argument for reading */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        /* Print an error message if the file cannot be opened */
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        /* Exit the program with status EXIT_FAILURE to indicate an error */
        exit(EXIT_FAILURE);
    }

    /* Process the file line by line */
    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Tokenize the line and process instructions here */
        /* You would typically parse the line and call the appropriate functions */
    }

    /* Free the memory allocated for the line buffer */
    free(line);

    /* Close the file when done */
    fclose(file);

    /* Return EXIT_SUCCESS to indicate successful execution */
    return (EXIT_SUCCESS);
}

