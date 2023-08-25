#include "monty.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_snodeint - add a node to the begininng of a linked list
 * @n: number
 * Return: Address of new head
 */

stack_t *add_snodeint(const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	if (head)
		(head)->prev = new_node;
	new_node->next = head;
	new_node->prev = NULL;
	head = new_node;
	if (!tail)
		tail = new_node
	return (head);
}
