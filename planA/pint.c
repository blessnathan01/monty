#include "monty.h"


/**
 * _pint - function that prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */

void  _pint(stack_t **stack, unsigned  int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
	UNUSED(line_number);
}
