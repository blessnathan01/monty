#include "monty.h"

/**
 * push - pushs value to the top of the stack
 * @stack: double pointer to the stack
 * @line_number: number of lines
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t **fresh_node;
	(void)line_number;

	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node != NULL)
	{
		fresh_node->n = argument;
		fresh_node->prev = NULL;
		fresh_node->next = NULL;

		if (*stack == NULL)
			*stack = fresh_node;
		else
		{
			fresh_node->next = *stack;
			(*stack)->prev = fresh_node;
			*stack = fresh_node;
		}
	}
	else
	{
		free_dlist(*stack);
		free(fresh_node);
		err(4);
	}
}

/**
 * pall - prints all arguments inserted
 * @stack: double pointer to the stack
 * @line_number: number of lines
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
