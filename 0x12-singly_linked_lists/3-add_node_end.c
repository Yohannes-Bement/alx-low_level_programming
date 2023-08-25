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
	list_t *JO;
	list_t *YO = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	JO = malloc(sizeof(list_t));
	if (!JO)
		return (NULL);

	JO->str = strdup(str);
	JO->len = len;
	JO->next = NULL;

	if (*head == NULL)
	{
		*head = JO;
		return (JO);
	}

	while (YO->next)
		YO = YO->next;

	YO->next = JO;

	return (JO);
}

