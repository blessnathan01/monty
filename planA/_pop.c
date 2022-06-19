#include "monty.h"

/**
 * _pop - remove the top item on the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 *
 * Return: nothing.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *present;

	present = NULL;
	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		clean_stack(stack);
		exit(EXIT_FAILURE);
	}
	present = *stack;
	*stack = present->next;
	if (present_>next != NULL)
		present->next->prev = present->prev;
	free(present);
}
