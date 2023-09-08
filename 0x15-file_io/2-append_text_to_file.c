#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int oxjo, wood, lejo = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lejo = 0; text_content[lejo];)
			lejo++;
	}

	oxjo = open(filename, O_WRONLY | O_APPEND);
	wood = write(oxjo, text_content, lejo);

	if (oxjo == -1 || wood == -1)
		return (-1);

	close(oxjo);

	return (1);
}

