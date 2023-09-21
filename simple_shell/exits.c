#include "shell.h"

/**
 **_sony - copies a string
 *@djohn: the destination string to be copied to
 *@srcjohn: the source string
 *@njohn: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_sony(char *djohn, char *srcjohn, int njohn)
{
	int ijohn, john;
	char *sjohn = djohn;

	ijohn = 0;
	while (srcjohn[ijohn] != '\0' && ijohn < njohn - 1)
	{
		djohn[ijohn] = srcjohn[ijohn];
		ijohn++;
	}
	if (ijohn < njohn)
	{
		john = ijohn;
		while (john < njohn)
		{
			djohn[john] = '\0';
			john++;
		}
	}
	return (sjohn);
}

/**
 **_strncatjohn - concatenates two strings
 *@destjohn: the first string
 *@srcjohn: the second string
 *@njohn: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncatjohn(char *destjohn, char *srcjohn, int njohn)
{
	int ijohn, john;
	char *sjohn = destjohn;

	ijohn = 0;
	john = 0;
	while (destjohn[ijohn] != '\0')
		ijohn++;
	while (srcjohn[john] != '\0' && john < njohn)
	{
		destjohn[ijohn] = srcjohn[john];
		ijohn++;
		john++;
	}
	if (john < njohn)
		destjohn[ijohn] = '\0';
	return (sjohn);
}

/**
 **_bnbb - locates a character in a string
 *@sjohn: the string to be parsed
 *@cjohn: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_bnbb(char *sjohn, char cjohn)
{
	do {
		if (*sjohn == cjohn)
			return (sjohn);
	} while (*sjohn++ != '\0');

	return (NULL);
}

