#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *john;
	int icon, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	john = malloc(sizeof(int) * size);

	if (john == NULL)
		return (NULL);

	for (icon = 0; min <= max; i++)
		john[i] = min++;

	return (john);
}

