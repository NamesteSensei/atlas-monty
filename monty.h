#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structures */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void push(stack_t **stack, unsigned int line_number, int n);
void pall(stack_t **stack, unsigned int line_number);
void execute(char *file_name);
int is_digit(char *str);
void free_stack(stack_t *stack);
void handle_error(unsigned int line_number, const char *message);

#endif /* MONTY_H */

