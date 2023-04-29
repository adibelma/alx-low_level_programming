#include "lists.h"

/**
 * add_nodeint - this function adds a new node at the beginning of a linked list listint_t
 * @head: Pointer to the 1st node list
 * @n: insert data into the new node
 *
 * Return: Pointer to new node && NULL if fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
