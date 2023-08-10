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
	char *john;
	char *yohanes;
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

	john = malloc(new_size);
	if (!john)
		return (NULL);

	yohanes = ptr;

	if (new_size < old_size)
	{
		for (icon = 0; icon < new_size; icon++)
			john[icon] = yohanes[icon];
	}

	if (new_size > old_size)
	{
		for (icon = 0; icon < old_size; icon++)
			john[icon] = yohanes[icon];
	}

	free(ptr);
	return (john);
}
