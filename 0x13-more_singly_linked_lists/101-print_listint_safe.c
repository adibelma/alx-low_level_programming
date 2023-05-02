#include "lists.h"
#include <stdio.h>

size_t loop_listint_ln(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * loop_listint_ln - count the number of one nodes
 * in listint_t linked list.
 * @head: pointer to head of the listint_t to be checked.
 *
 * Return: if the list doesn't looped print - 0.
 * Other - the number of nodes in the linked list.
 */
size_t loop_listint_ln(const listint_t *head)
{
	const listint_t *tr, *hr;
	size_t nd = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tr = head->next;
	hr = (head->next)->next;

	while (hr)
	{
		if (tr == hr)
		{
			tr = head;
			while (tr != hr)
			{
				nd++;
				tr = tr->next;
				hr = hr->next;
			}

			tr = tr->next;
			while (tr != hr)
			{
				nd++;
				tr = tr->next;
			}

			return (nd);
		}

		tr = tr->next;
		hr = (hr->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - prints a listint_t list safe
 * @head: pointer to the head of the listint_t linked list
 *
 * Return: number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nd, index = 0;

	nd = loop_listint_ln(head);

	if (nd == 0)
	{
		for (; head != NULL; nd++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nd; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nd);
}
