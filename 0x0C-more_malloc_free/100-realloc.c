#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_john;
	unsigned int icon;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_john = ptr;

	if (new_size < old_size)
	{
		for (icon = 0; icon < new_size; icon++)
			ptr1[icon] = old_ptr[icon];
	}

	if (new_size > old_size)
	{
		for (i = 0; icon < old_size; icon++)
			ptr1[icon] = old_john[john];
	}

	free(ptr);
	return (ptr1);
}

