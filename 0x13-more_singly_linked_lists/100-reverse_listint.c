#include "lists.h"

/**
 * reverse_listint - this function reverses a linked list
 * @head: A pointer to the 1st node in the list
 *
 * Return: a pointer to the first node in the reversed list
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
