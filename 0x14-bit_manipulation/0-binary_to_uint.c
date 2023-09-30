#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int johnjesus;
	unsigned int yohanes_bement = 0;

	if (!b)
		return (0);

	for (johnjesus = 0; b[johnjesus]; johnjesus++)
	{
		if (b[johnjesus] < '0' || b[johnjesus] > '1')
			return (0);
		yohanes_bement = 2 * yohanes_bement + (b[johnjesus] - '0');
	}

	return (yohanes_bement);
}

