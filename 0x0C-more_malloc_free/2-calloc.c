#include <stdlib.h>
#include "main.h"

/**
 * *_memset - fills memory with a constant byte
 * @sooman: memory area to be filled
 * @bobj: char to copy
 * @nna: number of times to copy b
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int icon;

	for (icon = 0; icon < nna; icon++)
	{
		sooman[icon] = bobj;
	}

	return (sooman);
}

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *john;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (john == NULL)
		return (NULL);

	_memset(john, 0, nmemb * size);

	return (john);

