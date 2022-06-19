#include "monty.h"

opret_q ret_and_q = {0, 0};

/**
 * check_codes - checks a command against all possible opcodes
 * @command: command found on a line
 * @stack: double pointer to the stack
 * @line_num: the line that the command was found
 *
 * Return: 1 if no command found,
 * opcode_return if command was found.
 */
int check_codes(char *command, stack_t **stack, size_t line_num)
{
	instruction_t opcodes[] = {
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"pchar", pchar},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{NULL, NULL}
	};
	size_t x;

	x = 0;
	while (opcodes[x].opcode != NULL)
	{
		if (strcmp(command, opcodes[x].opcode) == 0)
		{
			opcodes[x].f(stack, line_num);
			return (ret_and_q.opcode_return);
		}
		x++;
	}
	printf("L%lu: unknown instruction %s\n", line_num, command);
	ret_and_q.opcode_return = 1;
	return (1);
}
