#include "monty.h"


/**
 * _pop - removes the top element of the stack
 * @stack: pointer
 * @line_number: the line number
 * Return: void
 */

void  _pop(stack_t **stack, unsigned  int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	if ((*stack)->next)
		(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(ptr);
	UNUSED(line_number);
}
