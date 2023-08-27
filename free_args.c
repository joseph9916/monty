#include "monty.h"
#include <stdlib.h>

/**
 * free_args - free array args
 */
void free_args(void)
{
	int i = 1;

	while (opargs[i])
	{
		free(opargs[i]);
		i++;
	}
	free(opargs);
}
