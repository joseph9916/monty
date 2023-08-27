#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define _POSIX_C_SOURCE 200809L

char **opargs = NULL;

/**
 * exit_usage - exits because of usage
 * Return: Nothing
 */

void exit_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * exit_open - exits when opening
 * @filename: name of file
 * Return: Nothing
 */

void exit_open(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * main - main stack function
 * @ac: Number of arguements
 * @av: arguements
 * Return: 0 if successful or exits
 */

int main(int ac, char *av[])
{
	int line_no = 1;
	size_t n;
	char *line = NULL;
	stack_t *stack = NULL;
	FILE *monty;
	ssize_t nread;
	void (*f)(stack_t **, unsigned int);

	opargs = malloc(3 * sizeof(char *));
	if (!opargs)
		exit_malloc();
	if (ac != 2)
		exit_usage();
	monty = fopen(av[1], "r");
	if (!monty)
		exit_open(av[1]);
	nread = getline(&line, &n, monty);
	while (nread >= 0)
	{
		getop(line);
		f = get_instruction();
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opargs[0]);
			exit(EXIT_FAILURE);
		}
		f(&stack, line_no);
		nread = getline(&line, &n, monty);
		line_no++;
	}
	if (line)
		free(line);
	if (stack)
		free_stack(stack);
	if (opargs)
		free_args();
	fclose(monty);
	return (0);
}
