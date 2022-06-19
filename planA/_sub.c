#include "monty.h"

/**
 * _sub - subtracts the top item from the second item of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *present;
	int diff;

	present = *stack;
	diff = 0;
	if (!present || !present->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	diff = present->next->n - present->n;
	present->next->n = diff;
	_pop(stack, line_number);
}
