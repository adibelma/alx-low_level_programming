#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to the first node in the linked list
 *
 * Return: pointer to the first node of the reversed linked list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pv = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = pv;
		pv = *head;
		*head = next;
	}

	*head = pv;

	return (*head);
}
