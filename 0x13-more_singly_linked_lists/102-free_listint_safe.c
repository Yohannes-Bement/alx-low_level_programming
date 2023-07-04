#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t Yo = 0;
	int Jo;
	listint_t *To;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		Jo = *h - (*h)->next;
		if (Jo > 0)
		{
			To = (*h)->next;
			free(*h);
			*h = To;
			Yo++;
		}
		else
		{
			free(*h);
			*h = NULL;
			Yo++;
			break;
		}
	}

	*h = NULL;

	return (Yo);
}

