#include "monty.h"

char *g_arg = NULL;
int g_mode = 0;
/**
 * free_stack - frees all nodes in the stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * run_opcode - finds and executes the matching opcode function
 * @stack: pointer to the top of the stack
 * @opcode: the opcode string
 * @arg: argument to opcode (used by push)
 * @line_number: current line number in the file
 */
void run_opcode(stack_t **stack, char *opcode,
		char *arg, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", divop},
		{"mul", mul},
		{"sub", sub},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};
	int i;

	g_arg = arg;
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point for the Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp))
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;
		arg = strtok(NULL, " \t\n");
		run_opcode(&stack, opcode, arg, line_number);
	}
	fclose(fp);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
