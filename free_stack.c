#include "monty.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * free_stack - free the memory allocation of the stack
 * @stack: pointer to the linked list
 */

void free_stack(stack_t *stack)
{
	stack_t *curnode = stack, *temp;

	if (stack)
	{
		while (curnode)
		{
			temp = curnode;
			curnode = curnode->next;
			free(temp);
		}
		free(curnode);
	}
}
