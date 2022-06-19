#include "monty.h"

int value;

/**
 * fresh_node - creates a new node
 * @n: value
 *
 * Return: new node.
 */
stack_t *fresh_node(int n)
{
	stack_t *fresh = NULL;

	fresh = malloc(sizeof(stack_t));
	if (fresh == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	fresh->n = n;
	fresh->next = NULL;
	fresh->prev = NULL;

	return (fresh);
}

/**
 * _push - pushs value to the top of the stack
 * @stack: double pointer to the stack
 * @line_number: number of lines
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *fresh_node = NULL;
	(void)line_number;

	fresh_node = fresh_node(value);
	fresh_node->next = *stack;

	if (stack != NULL)
		(*stack)->prev = fresh_node;
	*stack = fresh_node;
}

/**
 * _pall - prints all arguments inserted on the stack
 * @stack: double pointer to the stack i.e. a parameter
 * @line_number: number of lines i.e. a value
 *
 * Return: nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *present = NULL;
	(void)line_number;

	present = *stack;
	while (present != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", present->line_number);
		present = present->next;
	}
}
