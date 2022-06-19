#include "monty.h"

/**
 * pchar - prints out the element of the code as it's corresponding value
 * on the ASCII table
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
		{
			printf("L%u: can't pchar, value out of range\n", line_num);
			ret_and_q.opcode_return = 1;
		}
		if (ret_and_q.opcode_return == 0)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
	else
	{
		printf("L%u: can't pchar, stack empty\n", line_num);
		ret_and_q.opcode_return = 1;
	}
}

/**
 * pstr - prints out every element of the stack as the corresponding character
 * on the ASCII table, stops if the value is 0, the stack is over, or the
 * value of the element is not in the ASCII table
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	if (*stack != NULL)
	{
		tmp = *stack;
		while (tmp != NULL && tmp->n > 0 && tmp->n <= 127)
		{
			putchar(tmp->n);
			tmp = tmp->next;
		}
	}
	putchar('\n');
}
