#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the elements that was deleted,
 * if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *ABL;
	int DAV;

	if (!head || !*head)
		return (0);

	DAV = (*head)->n;
	ABL = (*head)->next;
	free(*head);
	*head = ABL;

	return (DAV);
}

