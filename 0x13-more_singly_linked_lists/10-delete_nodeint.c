#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node in a linked list at index
 * @head: pointer to the first element in the linked list
 * @index: index of the node that should be deleted
 *
 * Return: 1 (success), or -1 (fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *cur = NULL;
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


	cur = tmp->next;
	tmp->next = cur->next;
	free(cur);

	return (1);
}
