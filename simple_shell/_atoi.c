#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_tomes - checks if character is a delimeter
 * @john: the char to check
 * @tomes: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_tomes(char john, char *tomes)
{
	while (*tomes)
		if (*tomes++ == john)
			return (1);
	return (0);
}

/**
 * _bement - checks for alphabetic character
 * @yohanes: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _bement(int yohanes)
{
	if ((yohanes >= 'a' && yohanes <= 'z') || (yohanes >= 'A' && yohanes <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _jesus - converts a string to an integer
 * @lord: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _jesus(char *lord)
{
	int ijohn, signjohn = 1, flagjohn = 0, outputjohn;
	unsigned int resultjohn = 0;

	for (ijohn = 0; lord[ijohn] != '\0' && flagjohn != 2; ijohn++)
	{
		if (lord[ijohn] == '-')
			signjohn *= -1;

		if (lord[ijohn] >= '0' && lord[ijohn] <= '9')
		{
			flagjohn = 1;
			resultjohn *= 10;
			resultjohn += (lord[ijohn] - '0');
		}
		else if (flagjohn == 1)
			flagjohn = 2;
	}

	if (signjohn == -1)
		outputjohn = -resultjohn;
	else
		outputjohn = resultjohn;

	return (outputjohn);
}

