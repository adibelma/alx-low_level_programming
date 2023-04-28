#include "lists.h"

/**
 * add_nodeint_end - this function adds a node at the end of a linked list listint_t
 * @head: Pointer to the 1st element in list
 * @n: insert data to new element
 *
 * Return: Pointer to the new element or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nv;
	listint_t *tmp = *head;

	new = malloc(sizeof(listint_t));
	if (!nv)
		return (NULL);

	nv->n = n;
	nv->next = NULL;

	if (*head == NULL)
	{
		*head = nv;
		return (nv);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = nv;

	return (nv);
}
