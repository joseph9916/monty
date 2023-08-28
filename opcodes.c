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
	stack_t *old_head;

	if ((*stack))
	{
		old_head = *stack;
		if ((*stack)->next)
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
		}
		else
			*stack = NULL;
		free(old_head);
	}
	else
	{
		free_args();
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
		free_args();
		free_stack(*stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * swap - swaps the top two values on the stacj
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *first = *stack, *second;

	if (!*stack)
		exit_swap(line_number);
	if (!((*stack)->next))
	{
		free_stack(*stack);
		exit_swap(line_number);
	}
	second = ((*stack)->next);
	temp = malloc(sizeof(stack_t));
	if (second->next)
	{
		temp->next = second->next;
		second->next->prev = temp;
	}
	else
		temp->next = NULL;
	second->next = temp;
	temp->prev = second;
	temp->n = first->n;
	free(first);
	*stack = second;
	second->prev = NULL;
}


/**
 * add - adds the top two values on the stack
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	if ((!*stack) || (!((*stack)->next)))
	{
		free_args();
		free_stack(*stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ((*stack)->n + (*stack)->next->n));
}


/**
 * nop - does nothing
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */


void nop(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	if (!(*stack))
	{
		;
	}
}








