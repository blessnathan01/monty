#include "monty.h"

/**
 * _pint - prints a value at the top of the stack
 * @stack: stack list
 * @line_number: line number
 *
 * Retrun: nothing.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleab_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
