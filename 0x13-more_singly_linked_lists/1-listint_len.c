#include "lists.h"

/**
 * listint_len - function that returns num of elements in a linked listint_t list
 * @h: linked list of the type listint_t To Traverse
 *
 * Return: nodes number
 */
size_t listint_len(const listint_t *h)
{
	size_t number_n = 0;

	while (h)
	{
		number_n++;
		h = h->next;
	}

	return (number_n);
}