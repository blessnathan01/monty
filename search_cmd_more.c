#include "monty.h"

/**
 * find_command - parses the line to find the given opcode
 * @line: a line grabbed from monty file
 * @stack: double pointer to the stack/queue
 * @line_num: line number
 *
 * Return: command name found
 **/
char *find_command(char *line, stack_t **stack, unsigned int line_num)
{
	char *cmd, *push_arg;

	cmd = strtok(line, "\n\t\r ");
	if (cmd == NULL || cmd[0] == '#')
		cmd = "nop";
	if (strcmp(cmd, "push") == 0)
	{
		cmd = "nop";
		push_arg = strtok(NULL, "\n \t\r");
		if (int_check(push_arg) == 0)
		{
			if (ret_and_q.queue_val == 0)
				add_node(stack, atoi(push_arg));
			else
				add_node_end(stack, atoi(push_arg));
		}
		else
		{
			printf("L%u: usage: push integer\n", line_num);
			ret_and_q.opcode_return = 1;
			return (cmd);
		}
	}
	if (strcmp(cmd, "stack") == 0)
	{
		cmd = "nop";
		ret_and_q.queue_val = 0;
		return (cmd);
	}
	if (strcmp(cmd, "queue") == 0)
	{
		cmd = "nop";
		ret_and_q.queue_val = 1;
		return (cmd);
	}
	return (cmd);
}

/**
 * int_check - checks if the given argument to push is a valid integer or not
 * @push_arg: a string argument found after the push opcode
 *
 * Return: 1 if it's not a valid integer,
 * 0 if it is a valid integer
 */
int int_check(char *push_arg)
{
	int x;

	if (push_arg == NULL)
		return (1);
	x = 0;
	while (push_arg[x] != '\0')
	{
		if (isalpha(push_arg[x]))
			return (1);
		x++;
	}
	return (0);
}

/**
 * add_node - adds a node to the top of stack
 * @stack: double pointer to the stack
 * @push_value: a value to assign to a new node
 *
 * Return: nothing.
 */
void add_node(stack_t **stack, int push_value)
{
	stack_t *fresh_node;

	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		if (*stack != NULL)
			(*stack)->prev = fresh_node;
		fresh_node->next = *stack;
		fresh_node->n = push_value;
		fresh_node->prev = NULL;
		*stack = fresh_node;
	}
}

/**
 * add_node_end - adds a node at the end of the list
 * @stack: double pointer to the stack
 * @push_value: a value to assign to the new node
 *
 * Return: nothing.
 */
void add_node_end(stack_t **stack, int push_value)
{
	stack_t *fresh_node;
	stack_t *slider;

	slider = *stack;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1)
	{
		while (slider != NULL && slider->next != NULL)
			slider = slider->next;
		fresh_node->n = push_value;
		fresh_node->next = NULL;
		fresh_node->prev = slider;
		if (slider != NULL)
			slider->next = fresh_node;
		else
			*stack = fresh_node;
	}
}
