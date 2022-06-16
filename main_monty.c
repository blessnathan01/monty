#include "monty.h"

global_t argument = {NULL, NULL};

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: argument array
 *
 * Return: number of arguments.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		handle_cmd(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * handle_cmd - reads file
 * @argv: argument array
 *
 * Return: nothing.
 */
void handle_cmd(char *argv)
{
	int count, result;
	size_t buf_size;
	char *args, *element;
	stack_t *stack;

	count = 0;
	result = 0;
	buf_size = 0;
	args = NULL;
	element = NULL;
	stack = NULL;

	argument.file_desc = fopen(argv, "r");
	if (argument.file_desc)
	{
		while (getline(&argument.line, &buf_size, argument.file_desc) != -1)
		{
			count++;
			args = strtok(argument.line, "\n\t\r");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;

			element = strtok(NULL, " \n\t\r");
			result = get_opcode(&stack, args, element, count);

			if (result == 1)
				push_err(argument.file_desc, argument.line, stack, count);
			else if (result == 2)
				ins_err(argument.file_desc, argument.line, stack, args, count);
		}

		free(argument.line);
		free_dlistint(stack);
		fclose(argument.file_desc);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
/**
 * get_opcode - handles opcode
 * @stack: a stack or queue
 * @arg: a parameter
 * @item: a parameter
 * @count: a line command
 * Return: nothing.
 */
int get_opcode(stack_t **stack, char *arg, char *item, int count)
{
	int x;

	x = 0;
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
