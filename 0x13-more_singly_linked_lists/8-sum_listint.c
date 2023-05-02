#include "lists.h"

/**
 * sum_listint - function returns the sum of all the data in a listint_t list
 * @head: first node in linked list
 *
 * Return: result sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *tmp = head;

	while (tmp)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}

	return (sum);
}
