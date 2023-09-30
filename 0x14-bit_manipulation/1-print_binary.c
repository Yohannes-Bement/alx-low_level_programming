#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int nap, jo = 0;
	unsigned long int cjo;

	for (nap = 63; nap >= 0; nap--)
	{
		cjo = n >> nap;

		if (cjo & 1)
		{
			_putchar('1');
			jo++;
		}
		else if (jo)
			_putchar('0');
	}
	if (!jo)
		_putchar('0');
}

