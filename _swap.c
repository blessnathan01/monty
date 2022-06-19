#include "monty.h"

/**
 * _swap - swaps the top two items of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *present;
	int tmp;

	present = *stack;
	tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}

	tmp = present->n;
	present->n = present->next->n;
	present->next->n = tmp;
}
