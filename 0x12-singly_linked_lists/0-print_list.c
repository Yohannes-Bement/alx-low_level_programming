#include <stdioh>
#include "lists.h"





/**
 * print_list.c - prints all the elements singly_linked_lists
 * @y: pointer to the list_t list to print
 *
 * Return: On success 0.
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (y)
	{
		if (!y->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", y->len, y->str);
		y = y->next;
		k++;
	}

	return (k);
}

