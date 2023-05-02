#include "lists.h"

/**
 * find_listint_loop - function finds the loop in a linked list
 * @head: the list to search for it
 *
 * Return: The address of the node where the loop starts, or NULL,
 * if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head;
	listint_t *f = head;

	if (!head)
		return (NULL);

	while (s && f && f->next)
	{
		f = f->next->next;
		s = s->next;
		if (f == s)
		{
			s = head;
			while (s != f)
			{
				s = s->next;
				f = fast->next;
			}
			return (f);
		}
	}

	return (NULL);
}
