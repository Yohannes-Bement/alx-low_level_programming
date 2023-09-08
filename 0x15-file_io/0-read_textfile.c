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
	char *boyjo;
	ssize_t foxjo;
	ssize_t yohan;
	ssize_t tom;

	foxjo = open(filename, O_RDONLY);
	if (foxjo == -1)
		return (0);
	boyjo = malloc(sizeof(char) * letters);
	tom = read(foxjo, boyjo, letters);
	yohan = write(STDOUT_FILENO, boyjo, tom);

	free(boyjo);
	close(foxjo);
	return (yohan); 
}

