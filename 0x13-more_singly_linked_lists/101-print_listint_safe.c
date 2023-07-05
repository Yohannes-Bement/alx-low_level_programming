#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *dav, *abl;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	dav = head->next;
	abl = (head->next)->next;

	while (abl)
	{
		if (dav == abl)
		{
			dav = head;
			while (dav != abl)
			{
				nodes++;
				dav = dav->next;
				abl = abl->next;
			}

			dav = dav->next;
			while (dav != abl)
			{
				nodes++;
				dav = dav->next;
			}

			return (nodes);
		}

		dav = dav->next;
		abl = (abl->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: a point to the head of the listint_t list.
 *
 * Return:  Number Of node in the List.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t yohanes, johnjesus = 0;

	yohanes = looped_listint_len(head);

	if (yohanes == 0)
	{
		for (; head != NULL; yohanes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (johnjesus = 0; johnjesus < yohanes; johnjesus++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (yohanes);
}

