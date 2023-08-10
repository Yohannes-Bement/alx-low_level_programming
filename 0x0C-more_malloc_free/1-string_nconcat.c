#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *john;
	unsigned int icon = 0, jo = 0, yo1 = 0, yo2 = 0;

	while (s1 && s1[yo1])
		yo1++;
	while (s2 && s2[yo2])
		yo2++;

	if (n < yo2)
		john = malloc(sizeof(char) * (yo1 + n + 1));
	else
		john = malloc(sizeof(char) * (yo1 + yo2 + 1));

	if (!john)
		return (NULL);

	while (icon < yo1)
	{
		john[icon] = s1[icon];
		icon++;
	}

	while (n < yo2 && icon < (yo1 + n))
		john[icon++] = s2[jo++];

	while (n >= yo2 && icon < (yo1 + yo2))
		john[icon++] = s2[jo++];


	john[icon] = '\0';

	return (john);
}

