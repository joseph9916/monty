#include "monty.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * exit_malloc - exits in malloc failure
 * Return: Nothing
 */

void exit_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * getop - get operations from line
 * @line: line input
 * Return: Nothing
 */

void getop(char *line)
{
	char *token;
	char delim[] = " \t\n";
	int i = 0;

	token = strtok(line, delim);
	while (i < 3)
	{
		if (token)
			opargs[i] = token;
		else
		{
			opargs[i] = NULL;
			return;
		}
		i++;
		token = strtok(NULL, delim);
	}
}

/**
 * get_instruction - get instruction for opcode
 * Return: function to use
 */

void (*get_instruction(void))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (!strcmp(ops[i].opcode, opargs[0]))
			return (ops[i].f);
	}
	return (NULL);
}

/**
 * push - pushes an element to the stack.
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_stack(*stack);
		exit_malloc();
	}
	if ((!opargs[1]) || (strspn(opargs[1], "0123456789")
			!= strlen(opargs[1])))
	{
		free_args();
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(opargs[1]);
	if (!(*stack))
	{
		*stack = new_node;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		new_node->prev = NULL;
		(*stack) = new_node;
	}
}

/**
 * pall - prints all the values on the stack, starting from the top of the
 * stack.
 * @stack: stack linked list
 * @line_number: line number presently
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *curnode;

	if (!(*stack))
		return;
	for (curnode = *stack; curnode; curnode = curnode->next)
		printf("%d\n", curnode->n);
}
