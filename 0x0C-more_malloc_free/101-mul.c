#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int icon = 0;

	while (s[icon])
	{
		if (s[icon] < '0' || s[icon] > '9')
			return (0);
		icon++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int icon = 0;

	while (s[icon] != '\0')
	{
		icon++;
	}
	return (icon);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *yohanes1, *john2;
	int lens1, leng2, lent, icon, car, dig1, dig2, *res, a = 0;

	yohanes1 = argv[1], john2 = argv[2];
	if (argc != 3 || !is_digit(yohanes1) || !is_digit(john2))
		errors();
	lens1 = _strlen(yohanes1);
	leng2 = _strlen(john2);
	lent = lens1 + leng2 + 1;
	res = malloc(sizeof(int) * lent);
	if (!res)
		return (1);
	for (icon = 0; icon <= lens1 + leng2; icon++)
		res[icon] = 0;
	for (lens1 = lens1 - 1; lens1 >= 0; lens1--)
	{
		dig1 = yohanes1[lens1] - '0';
		car = 0;
		for (leng2 = _strlen(john2) - 1; leng2 >= 0; leng2--)
		{
			dig2 = john2[leng2] - '0';
			car += res[lens1 + leng2 + 1] + (dig1 * dig2);
			res[lens1 + leng2 + 1] = car % 10;
			car /= 10;
		}
		if (car > 0)
			res[lens1 + leng2 + 1] += car;
	}
	for (icon = 0; icon < lent - 1; icon++)
	{
		if (res[icon])
			a = 1;
		if (a)
			_putchar(res[icon] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}

