#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: Point to the First element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer  the new node,  NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *jojesus;
	listint_t *tom = *head;

	jojesus = malloc(sizeof(listint_t));
	if (!jojesus)
		return (NULL);

	jojesus->n = n;
	jojesus->next = NULL;

	if (*head == NULL)
	{
		*head = jojesus;
		return (jojesus);
	}

	while (tom->next)
		tom = tom->next;

	tom->next = jojesus;

	return (jojesus);
}

