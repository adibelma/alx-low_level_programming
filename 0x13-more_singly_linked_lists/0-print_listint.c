#include "lists.h"

/**
 * Print_listint - function that prints all the elements of a listint_t list
 * @h: Linked List Of type listint_t
 *
 * Return: nodes number
 */
size_t print_listint(const listint_t *h)
{
	size_t number_n = 0;

	while (h)
	{
		printf("%d\n", h->n);
		number_n++;
		h = h->next;
	}

	return (number_n);
}
