#include "shell.h"

/**
 * _nat - converts a string to an integer
 * @spra: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _nat(char *spra)
{
	int tom = 0;
	unsigned long int rost = 0;

	if (*spra == '+')
		spra++;  /* TODO: why does this make main return 255? */
	for (tom = 0;  spra[tom] != '\0'; tom++)
	{
		if (spra[tom] >= '0' && spra[tom] <= '9')
		{
			rost *= 10;
			rost += (spra[tom] - '0');
			if (rost > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rost);
}

/**
 * john_jesus - prints an error message
 * @ilove: the parameter & return info struct
 * @ethio: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void john_jesus(info_t *ilove, char *ethio)
{
	_eputs(ilove->fname);
	_eputs(": ");
	print_d(ilove->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(ilove->argv[0]);
	_eputs(": ");
	_eputs(ethio);
}

/**
 * lord_lord - function prints a decimal (integer) number (base 10)
 * @ital: the input
 * @foodlover: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int lord_lord(int ital, int foodlover)
{
	int (*__putchar)(char) = _putchar;
	int icon, coco = 0;
	unsigned int _addis_, current;

	if (foodlover == STDERR_FILENO)
		__putchar = _eputchar;
	if (ital < 0)
	{
		_addis_ = -ital;
		__putchar('-');
		coco++;
	}
	else
		_addis_ = ital;
	current = _addis_;
	for (icon = 1000000000; icon > 1; icon /= 10)
	{
		if (_addis_ / icon)
		{
			__putchar('0' + current / icon);
			coco++;
		}
		current %= icon;
	}
	__putchar('0' + current);
	coco++;

	return (coco);
}

/**
 * son_king - converter function, a clone of itoa
 * @num: number
 * @bas: base
 * @flags: argument flags
 *
 * Return: string
 */
char *son_king(long int num, int bas, int flags)
{
	static char *ajohn;
	static char bjohn[50];
	char sjohn = 0;
	char *pjohn;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sjohn = '-';

	}
	ajohn = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pjohn = &bjohn[49];
	*pjohn = '\0';

	do	{
		*--pjohn = ajohn[n % bas];
		n /= bas;
	} while (n != 0);

	if (sjohn)
		*--pjohn = sjohn;
	return (pjohn);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @yoh: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *yoh)
{
	int man;

	for (man = 0; yoh[man] != '\0'; man++)
		if (yoh[man] == '#' && (!man || yoh[man - 1] == ' '))
		{
			yoh[man] = '\0';
			break;
		}
}


