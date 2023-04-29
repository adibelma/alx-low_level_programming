#include "lists.h"

/**
 * sum_listint - this function calculates the sum of all the data in a listint_t list
 * @head: the 1st node in link list
 * Return: sum
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
