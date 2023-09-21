#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t rjohn = 0;
	size_t len_pjohn = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rjohn = getline(buf, &len_pjohn, stdin);
#else
		rjohn = _getline(info, buf, &len_pjohn);
#endif
		if (rjohn > 0)
		{
			if ((*buf)[rjohn - 1] == '\n')
			{
				(*buf)[rjohn - 1] = '\0'; /* remove trailing newline */
				rjohn--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = rjohn;
				info->cmd_buf = buf;
			}
		}
	}
	return (rjohn);
}

/**
 * get_inputjohn - gets a line minus the newline
 * @infojohn: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_inputjohn(info_t *infojohn)
{
	static char *bufjohn; /* the ';' command chain buffer */
	static size_t ijohn, john, lenjohn;
	ssize_t rjohn = 0;
	char **buf_pjohn = &(infojohn->arg), *pjohn;

	_putchar(BUF_FLUSH);
	rjohn = input_buf(infojohn, &bufjohn, &lenjohn);
	if (rjohn == -1) /* EOF */
		return (-1);
	if (lenjohn) /* we have commands left in the chain buffer */
	{
		john = ijohn; /* init new iterator to current buf position */
		pjohn = bufjohn + ijohn; /* get pointer for return */

		check_chain(infojohn, bufjohn, &john, ijohn, lenjohn);
		while (john < lenjohn) /* iterate to semicolon or end */
		{
			if (is_chain(infojohn, bufjohn, &john))
				break;
			john++;
		}

		ijohn = john + 1; /* increment past nulled ';'' */
		if (ijohn >= lenjohn) /* reached end of buffer? */
		{
			ijohn = lenjohn = 0; /* reset position and length */
			infojohn->cmd_buf_type = CMD_NORM;
		}

		*buf_pjohn = pjohn; /* pass back pointer to current command position */
		return (_strlen(pjohn)); /* return length of current command */
	}

	*buf_pjohn = bufjohn; /* else not a chain, pass back buffer from _getline() */
	return (rjohn); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *ijohn)
{
	ssize_t rjohn = 0;

	if (*ijohn)
		return (0);
	rjohn = read(info->readfd, buf, READ_BUF_SIZE);
	if (rjohn >= 0)
		*ijohn = rjohn;
	return (rjohn);
}

/**
 * _getlinejohn - gets the next line of input from STDIN
 * @infojohn: parameter struct
 * @ptrjohn: address of pointer to buffer, preallocated or NULL
 * @lengthjohn: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getlinejohn(info_t *infojohn, char **ptrjohn, size_t *lengthjohn)
{
	static char buf[READ_BUF_SIZE];
	static size_t ijohn, lenjohn;
	size_t kjohn;
	ssize_t rjohn = 0, sjohn = 0;
	char *pjohn = NULL, *new_pjohn = NULL, *cjohn;

	pjohn = *ptrjohn;
	if (pjohn && lengthjohn)
		sjohn = *lengthjohn;
	if (ijohn == lenjohn)
		ijohn = lenjohn = 0;

	rjohn = read_buf(infojohn, buf, &lenjohn);
	if (rjohn == -1 || (rjohn == 0 && lenjohn == 0))
		return (-1);

	cjohn = _strchr(buf + ijohn, '\n');
	kjohn = cjohn ? 1 + (unsigned int)(cjohn - buf) : lenjohn;
	new_pjohn = _realloc(pjohn, sjohn, sjohn ? sjohn + kjohn : kjohn + 1);
	if (!new_pjohn) /* MALLOC FAILURE! */
		return (pjohn ? free(pjohn), -1 : -1);

	if (sjohn)
		_strncat(new_pjohn, buf + ijohn, kjohn - ijohn);
	else
		_strncpy(new_pjohn, buf + ijohn, kjohn- ijohn + 1);

	sjohn += kjohn - ijohn;
	ijohn = kjohn;
	pjohn = new_pjohn;

	if (lengthjohn)
		*lengthjohn = sjohn;
	*ptrjohn = pjohn;
	return (sjohn);
}

/**
 * tomjohn - blocks ctrl-C
 * @sjo_njo: the signal number
 *
 * Return: void
 */
void tomjohn(__attribute__((unused))int sjo_njo)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

