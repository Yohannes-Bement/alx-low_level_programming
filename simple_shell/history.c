#include "shell.h"

/**
 * hellw_world_file - gets the history file
 * @infojohn: parameter struct
 *
 * Return: allocated string containg history file
 */

char *hellw_world_file(info_t *infojohn)
{
	char *alme, *hana;

	hana = _getenv(infojohn, "HOME=");
	if (!hana)
		return (NULL);
	alme = malloc(sizeof(char) * (_strlen(hana) + _strlen(HIST_FILE) + 2));
	if (!alme)
		return (NULL);
	alme[0] = 0;
	_strcpy(alme, hana);
	_strcat(alme, "/");
	_strcat(alme, HIST_FILE);
	return (alme);
}

/**
 * yohanes_jo - creates a file, or appends to an existing file
 * @infojohn: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int yohanes_jo(info_t *infojohn)
{
	ssize_t fjohn;
	char *filejohn = get_history_file(infojohn);
	list_t *node = NULL;

	if (!filejohn)
		return (-1);

	fjohn = open(filejohn, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filejohn);
	if (fjohn == -1)
		return (-1);
	for (node = infojohn->history; node; node = node->next)
	{
		_putsfd(node->str, fjohn);
		_putfd('\n', fjohn);
	}
	_putfd(BUF_FLUSH, fjohn);
	close(fjohn);
	return (1);
}
/**
 * royal_john - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int royal_john(info_t *info)
{
	int icon, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (icon = 0; icon < fsize; icon++)
		if (buf[icon] == '\n')
		{
			buf[icon] = 0;
			build_history_list(info, buf + last, linecount++);
			last = icon + 1;
		}
	if (last != icon)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}


/**
 * john_jesus_list - adds entry to a history linked list
 * @nap: Structure containing potential arguments. Used to maintain
 * @boy: buffer
 * @yohanes: the history linecount, histcount
 *
 * Return: Always 0
 */
int john_jesus_list(info_t *nap, char *boy, int yohanes)
{
	list_t *node = NULL;

	if (nap->history)
		node = nap->history;
	add_node_end(&node, boy, yohanes);

	if (!nap->history)
		nap->history = node;
	return (0);
}

/**
 * nat_treff - renumbers the history linked list after changes
 * @john: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int nat_treff(info_t *john)
{
	list_t *node = john->history;
	int icon = 0;

	while (node)
	{
		node->num = icon++;
		node = node->next;
	}
	return (john->histcount = icon);
}

