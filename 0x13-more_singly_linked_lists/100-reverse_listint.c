#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *Ms = NULL;
	listint_t *Be = NULL;

	while (*head)
	{
		Be = (*head)->next;
		(*head)->next = Ms;
		Ms = *head;
		*head = Be;
	}

	*head = Ms;

	return (*head);
}


