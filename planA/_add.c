#include "monty.h"

/**
 * _add - adds two integers
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *present;
	int total;

	present = NULL;
	total = 0;
	if (!*stack || !*(stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	present = *stack;
	total = present->n + present->next->n;
	present->next->n = total;
	_pop(stack, line_number);
}
