#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int number;

	if (!head || !*head)
		return (0);

	number = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (number);
}
