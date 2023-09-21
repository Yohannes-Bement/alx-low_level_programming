#include "shell.h"

/**
 * _mom - prints an input string
 * @dad: the string to be printed
 *
 * Return: Nothing
 */
void _mom(char *dad)
{
	int unc = 0;

	if (!dad)
		return;
	while (dad[unc] != '\0')
	{
		_eputchar(dad[unc]);
		unc++;
	}
}

/**
 * _john - writes the character c to stderr
 * @jesus: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _john(char jesus)
{
	static int nap;
	static char buf[WRITE_BUF_SIZE];

	if (jesus == BUF_FLUSH || nap >= WRITE_BUF_SIZE)
	{
		write(2, buf, nap);
		nap = 0;
	}
	if (jesus != BUF_FLUSH)
		buf[nap++] = jesus;
	return (1);
}

/**
 * _yohanes - writes the character c to given fd
 * @bement: The character to print
 * @brhanu: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _yohnaes(char bement, int brhanu)
{
	static int tom;
	static char buf[WRITE_BUF_SIZE];

	if (bement == BUF_FLUSH || tom >= WRITE_BUF_SIZE)
	{
		write(brhanu, buf, tom);
		tom = 0;
	}
	if (bement != BUF_FLUSH)
		buf[tom++] = bement;
	return (1);
}

/**
 * _bke - prints an input string
 * @john: the string to be printed
 * @jesus: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _bke(char *john, int jesus)
{
	int ice = 0;

	if (!john)
		return (0);
	while (*john)
	{
		ice += _putfd(*john++, jesus);
	}
	return (ice);
}

