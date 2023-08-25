#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *johnjesus;

	while (head)
	{
		johnjesus = head->next;
		free(head->str);
		free(head);
		head = johnjesus;
	}
}

