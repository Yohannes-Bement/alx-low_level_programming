#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *mhr;
	listint_t *ads = *head;

	mrh = malloc(sizeof(listint_t));
	if (!mhr)
		return (NULL);

	mhr = n;
	mhr->next = NULL;

	if (*head == NULL)
	{
		*head = mhr;
		return (mhr);
	}

	while (ads->next)
		ads = ads->next;

	ads->next = mhr;

	return (mhr);
}

