#include "monty.h"

/**
 * push - pushes an integer onto the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int i, is_num;
	char *arg = g_arg;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	is_num = 1;
	for (i = (arg[0] == '-' ? 1 : 0); arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			is_num = 0;
			break;
		}
	}
	if (!is_num || arg[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack from top to bottom
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * divop - divides the second top element by the top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void divop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * mul - multiplies the second top element by the top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
