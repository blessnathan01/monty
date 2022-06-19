#include "monty.h"

/**
 * main - loops through given file and run given opcode
 * @argc: length of argv array
 * @argv: array of strings
 *
 * Return: 1 if reaches end of the file,
 * exit with EXIT_FAILURE if any opcode fails
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line, *cmd;
	size_t size, line_num;
	stack_t *stack;
	ssize_t read = 0;

	stack = NULL;
	line = NULL;
	size = 0;
	line_num = 1;
	if (argc != 2)
	{
		printf("usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, file);
	while (read != -1)
	{
		cmd = find_command(line, &stack, line_num);
		if (strcmp(cmd, "nop"))
			check_codes(cmd, &stack, line_num);
		if (ret_and_q.opcode_return != 0)
		{
			free_and_exit(line, file, stack);
		}
		line_num++;
		read = getline(&line, &size, file);
	}
	free_stack(stack);
	free(line);
	fclose(file);
	return (0);
}

/**
 * free_and_exit - frees all necessary memory and exits with EXIT_FAILURE
 * @line: line found with getline()
 * @file: file opened and being read from
 * @stack: pointer to the stack
 *
 * Return: nothing.
 */
void free_and_exit(char *line, FILE *file, stack_t *stack)
{
	free_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees all nodes of the stack
 * @stack: pointer to the stack
 *
 * Return: nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *kill_node;

	while (stack != NULL)
	{
		kill_node = stack;
		stack = stack->next;
		free(kill_node);
	}
}
