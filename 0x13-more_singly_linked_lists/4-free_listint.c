#include "lists.h"

/**
 * free_listint - this function frees a linked list listint_t
 * @head: list to frees listint_t 
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
