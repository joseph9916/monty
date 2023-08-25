#include "monty.h"
#include <stddef.h>

char **getop(char *line)
{
	char **opargs = malloc(2 * sizeof(char *));
	char *token;
	char delim[] = "\t\n ";
	int i = 0;

	token = strtok(line, delim);
	while (i < 2)
	{
		if (token)
			opargs[i] = token;
		else
		{
			opargs[i] = NULL;
			return opargs;
		}
		i++;
	}
	return opargs
}

void get_instruction(char **opargs, int line_no)(stack_t, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{"pint", pint},
		{"pall", pall},
		{NULL, NULL}
	}
	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (!_strcmp(ops[i].opcode, opargs[0]))
			return (ops[i].f);
	}
}
