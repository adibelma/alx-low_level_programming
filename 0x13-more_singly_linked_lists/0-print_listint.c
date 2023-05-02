#include "lists.h"

/**
 * print_listint - Prints elements of a linked list
 * at h: linked list of type listint_t to print
 *
 * Returns : numbers of nodes : this project created by Adib Elmarbout
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
