#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *yohanes = head;
	listint_t *johnjesus = head;

	if (!head)
		return (NULL);

	while (yohanes && johnjesus && johnjesus->next)
	{
		johnjesus = johnjesus->next->next;
		yohanes = yohanes->next;
		if (johnjesus == yohanes)
		{
			yohanes = head;
			while (yohanes != johnjesus)
			{
				yohanes = yohanes->next;
				johnjesus = johnjesus->next;
			}
			return (johnjesus);
		}
	}

	return (NULL);
}

