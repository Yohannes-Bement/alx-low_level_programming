#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int nap, cojo = 0;
	unsigned long int cjo;
	unsigned long int ejo = n ^ m;

	for (nap = 63; nap >= 0; nap--)
	{
		cjo = ejo >> nap;
		if (cjo & 1)
			cojo++;
	}

	return (cojo);
}

