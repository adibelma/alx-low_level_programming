#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head;
	listint_t *f = head;

	if (!head)
		return (NULL);

	while (s && f && f->nxt)
	{
		f = f->nxt->nxt;
		s = s->nxt;
		if (f == s)
		{
			s = head;
			while (s != f)
			{
				s = s->nxt;
				f = f->nxt;
			}
			return (f);
		}
	}

	return (NULL);
}
