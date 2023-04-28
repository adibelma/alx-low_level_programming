#include "lists.h"

/**
 * pop_listint - this function deletes the head node of a linked list and returns the head
 * node’s data (n)
 * @head: point to the 1st element in the linked list
 * Return: data inside the elements that was deleted,
 * or 0 if the linked list is empty 
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
