#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void exit_usage(void)
{
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void exit_open(const char *filename)
{
	dprintf(2, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

int main(int ac, char *av[])
{
	int line_no = 1;
	char *line = NULL, **opargs;
	size_t n = 0;
	FILE *monty;

	if (ac != 2)
		exit_usage();
	monty = fopen(av[1], r);
	if (!monty)
		exit_open(av[1]);
	nread = getline(&line, &n, monty);
	while (nread > 0)
	{
		opargs = getop(line);
		execute_ops(opargs, line_no);
		nread = getline(&line, &n, monty);
		line_no++;
	}
	return (0);
}
