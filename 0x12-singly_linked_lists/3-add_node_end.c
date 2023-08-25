#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
 	list_t *john;
	list_t *t = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	john = malloc(sizeof(list_t));
	if (!john)
		return (NULL);

	john->str = strdup(str);
	john->len = len;
	john->next = NULL;

	if (*head == NULL)
	{
		*head = john;
		return (john);
	}

	while (t->next)
		t = t->next;

	t->next = john;

	return (john);
}

