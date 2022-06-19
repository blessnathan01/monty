#include "monty.h"

/**
 * rotl - puts top element at the bottom and second element at the top of stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *slider, *first_node, *second_node;

	(void) line_num;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		slider = first_node = *stack;
		second_node = slider->next;
		while (slider->next != NULL)
		{
			slider = slider->next;
		}
		slider->next = first_node;
		first_node->prev = slider;
		first_node->next = NULL;
		second_node->prev = NULL;
		*stack = second_node;
	}
}

/**
 * rotr - puts the bottom element at the top of stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *last_node, *second_last_node;

	(void) line_num;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		second_last_node = last_node->prev;
		second_last_node->next = NULL;
		last_node->next = *stack;
		last_node->prev = NULL;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}
