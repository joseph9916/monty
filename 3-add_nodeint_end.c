#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * add_dnodeint_end - add a node to the end of a linked list
 * @head: pointer to the head of the linked list
 * @n: number to copy to ths new head
 * Return: Address of new address
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *cur_node = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return (*head);
	}
	while (cur_node->next)
		cur_node = cur_node->next;
	cur_node->next = new_node;
	new_node->next = NULL;
	new_node->prev = cur_node;

	return (*head);
}
