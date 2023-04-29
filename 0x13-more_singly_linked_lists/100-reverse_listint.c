#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pv = NULL;
	listint_t *nxt = NULL;

	while (*head)
	{
		nxt = (*head)->nxt;
		(*head)->nxt = pv;
		pv = *head;
		*head = nxt;
	}

	*head = pv;

	return (*head);
}
