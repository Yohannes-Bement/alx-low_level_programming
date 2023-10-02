#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bjo;
	ssize_t fjo;
	ssize_t wjo;
	ssize_t tjo;

	fjo = open(filename, O_RDONLY);
	if (fjo == -1)
		return (0);
	bjo = malloc(sizeof(char) * letters);
	tjo = read(fjo, bjo, letters);
	wjo = write(STDOUT_FILENO, bjo, tjo);

	free(bjo);
	close(fjo);
	return (wjo);
}

