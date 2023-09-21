#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @sj: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *sj, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		sj[i] = b;
	return (sj);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **aj = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(aj);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pj;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pj = malloc(new_size);
	if (!pj)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pj[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pj);
}

