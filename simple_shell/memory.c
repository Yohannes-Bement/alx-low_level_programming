#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptrj: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptrj)
{
	if (ptrj && *ptrj)
	{
		free(*ptrj);
		*ptrj = NULL;
		return (1);
	}
	return (0);
}

