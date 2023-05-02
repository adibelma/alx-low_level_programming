#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: A pointer to the first node in the listint_t linked list
 *
 * Return: size of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t ln = 0;
	int d;
	listint_t *tmp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		d = *h - (*h)->next;
		if (d > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			ln++;
		}
		else
		{
			free(*h);
			*h = NULL;
			ln++;
			break;
		}
	}

	*h = NULL;

	return (ln);
}
