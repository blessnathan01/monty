#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* Data Structures - Stacks */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_s - globally access
 * @file_desc: file descriptor
 * @line: line to getline
 *
 * Description: handles a file and getline
 */
typedef struct global_s
{
	FILE *file_desc;
	char *line;
} global_t;

/*global variable*/
extern global_t argument;
extern int value;

void handle_cmd(char *argv);
int get_opcode(stack_t **stack, char *arg, char *item, int count);

/* Function Prototypes */
/* Opcode Functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void handle_cmd(char *argv);
int get_opcode(stack_t **stack, char *arg, char *item, int count);
void free_dlistint(stack_t *stack);
void clean_stack(stack_t **stack);

/* Help Functions */
int _isdigit(char *c);
stack_t *fresh_node(int n);

/* Handle Errors */
void push_err(FILE *file_desc, char *line, stack_t *stack, int count);
void ins_err(FILE *file_desc, char *line, stack_t stack, char *count, int item);

#endif /* MONTY_H */
