#include "monty.h"
#include <stdlib.h>

/**
 * free_args - free array args
 */
void free_args(void)
{
	free(opargs);
}
