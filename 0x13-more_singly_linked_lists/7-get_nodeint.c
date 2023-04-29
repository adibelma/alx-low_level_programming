#include "lists.h"

/**
 * get_nodeint_at_index - this function returns the nth node at a certain index in a linked list
 * @head: 1st node in linked list
 * @index: index of returned nodes 
 * 
 * Return: where index is the index of the node, starting at 0
 * if the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *tmp = head;

	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	return (tmp ? tmp : NULL);
}
