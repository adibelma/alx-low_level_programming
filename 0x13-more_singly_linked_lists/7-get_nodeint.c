#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node at a certain index of a listint_t linked list
 * @head: first node in the linked list listint_t
 * @index: index of the node returned
 *
 * Return: pointer to the node where index of the node, starting at 0
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
