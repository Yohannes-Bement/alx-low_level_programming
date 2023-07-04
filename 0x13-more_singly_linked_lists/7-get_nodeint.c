#include "lists.h"











/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: FRIST node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node we're looking for,  NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int yohanes = 0;
	listint_t *johnjesus = head;

	while (johnjesus && yohanes < index)
	{
		johnjesus = johnjesus->next;
		yohanes++;
	}

	return (johnjesus ? johnjesus : NULL);
}

