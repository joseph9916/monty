#include "monty.h"
#include <stdlib.h>

/**
 * exit_swap - exits if stack is too shork for a swap
 * @line_number: line number of bytecode
 */

void exit_swap(unsigned int line_number)
{
	free_args();
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
