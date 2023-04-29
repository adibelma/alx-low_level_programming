#include "lists.h"

/**
 * free_listint_safe - this finction frees a linked list
 * @h: A pointer to the 1st node in the linked list
 *
 * Return: The size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int d;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		d = *h - (*h)->nxt;
		if (d > 0)
		{
			tmp = (*h)->nxt;
			free(*h);
			*h = tmp;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}

	*h = NULL;

	return (l);
}
