#include "lists.h"

/**
 * free_listint2 - function frees a linked list listint_t
 * @head: listint_t list to be freed, function sets the head to NULL
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}

	*head = NULL;
}
