#include "monty.h"

/**
 * _free_dlistint - frees a list
 * @stack: pointer to the head
 *
 * Return: nothing.
 */
void free_dlistint(stack_t *stack)
{
	stack_t *present = NULL;

	present = stack;

	if (present != NULL)
	{
		free_dlistint(present->next);
		free(present);
	}
}
