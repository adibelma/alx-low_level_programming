#include "lists.h"

/**
 * add_nodeint - adds a new node at the end of a listint-t list
 * @head: pointer to the first nodes in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nouveau;

	nouveau = malloc(sizeof(listint_t));
	if (!nouveau)
		return (NULL);

	nouveau->n = n;
	nouveau->next = *head;
	*head = nouveau;

	return (nouveau);
}

