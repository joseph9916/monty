#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * free_dlistint - free the memory allocation of linked list
 * @head: pointer to the linked list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *curnode = head, *temp;

	if (head)
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
