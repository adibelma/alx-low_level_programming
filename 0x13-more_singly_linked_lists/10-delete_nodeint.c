#include "lists.h"

/**
 * delete_nodeint_at_index - this function deletes a node in a linked list at index index
 * @head: Pointer to the 1st element in the list
 * @index:  index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if (Succeeded), or -1 if (Failed)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *c = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		i++;
	}


	c = tmp->next;
	tmp->next = c->next;
	free(c);

	return (1);
}
