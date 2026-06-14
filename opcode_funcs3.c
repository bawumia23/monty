#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tail;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	tail->next = tmp;
	tmp->prev = tail;
	tmp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}
/**
 * stack_mode - sets the mode to LIFO (stack)
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_mode = 0;
}

/**
 * queue_mode - sets the mode to FIFO (queue)
 * @stack: pointer to the top of the stack (unused)
 * @line_number: current line number (unused)
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_mode = 1;
}
