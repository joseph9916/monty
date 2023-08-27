#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - pop the last number
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next_head;

	next_head = (*stack)->next;
	if (*stack)
	{
		next_head->prev = NULL;
		free(*stack);
		*stack = next_head;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
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
