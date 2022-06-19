#include "monty.h"

/**
 * add - adds the top two elements of the stack and stores sum in second node,
 * set the pointer to the second node, then remove the top node
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp->next->n += tmp->n;
		pop(stack, line_num);
	}
}

/**
 * sub - subtracts the top element of the stack from the second
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL ||  tmp->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp->next->n -= tmp->n;
		pop(stack, line_num);
	}
}

/**
 * _div - divides the second element of the stack by the first
 * @stack: double pointer of the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (tmp != NULL && ret_and_q.opcode_return != 1 && tmp->n == 0)
	{
		printf("L%u: division by zero\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp->next->n /= tmp->n;
		pop(stack, line_num);
	}
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp->next->n *= tmp->n;
		pop(stack, line_num);
	}
}

/**
 * mod - calculates the remainder after division of two top elements of the stack
 * @stack: double pointer to the stack
 * @line_num: line number
 *
 * Return: nothing.
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (tmp != NULL && tmp->n == 0 && ret_and_q.opcode_return != 1)
	{
		printf("L%u: division by zero\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		tmp->next->n %= tmp->n;
		pop(stack, line_num);
	}
}
