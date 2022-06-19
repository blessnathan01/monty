#include "monty.h"

/**
 * pall - prints all elements in the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *kill_node, *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		kill_node = tmp;
		*stack = tmp->next;
		if (tmp != NULL)
			tmp->prev = NULL;
		free(kill_node);
	}
}

/**
 * swap - swaps two top elements of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *slider;
	int tmp;

	slider = *stack;
	if (slider == NULL || slider->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp = slider->n;
		slider->n = slider->next->n;
		slider->next->n = tmp;
	}
}

/**
 * pint - prints the top element of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		printf("%d\n", (*stack)->n);
	}
}
