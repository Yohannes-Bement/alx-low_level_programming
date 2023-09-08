#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_boyjo(char *foxjo);
void close_foxjo(int fdoxjo);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_boyjo(char *foxjo)
{
	char *boyjo;

	boyjo = malloc(sizeof(char) * 1024);

	if (boyjo == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", foxjo);
		exit(99);
	}

	return (boyjo);
}

/**
 * close_foxjo - Closes file descriptors.
 * @fdxjo: The file descriptor to be closed.
 */
void close_foxjo(int fdxjo)
{
	int johnc;

	johnc = close(fdxjo);

	if (johnc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdxjo);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fro, too, row, wood;
	char *boyjo;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	boyjo = create_boyjo(argv[2]);
	fro = open(argv[1], O_RDONLY);
	row = read(fro, boyjo, 1024);
	too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fro == -1 || row == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(boyjo);
			exit(98);
		}

		wood = write(too, boyjo, row);
		if (too == -1 || wood == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(boyjo);
			exit(99);
		}

		row = read(fro, boyjo, 1024);
		too = open(argv[2], O_WRONLY | O_APPEND);

	} while (row > 0);

	free(boyjo);
	close_foxjo(fro);
	close_foxjo(too);

	return (0);
}

