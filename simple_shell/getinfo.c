#include "shell.h"

/**
 * john_jesus - initializes info_t struct
 * @lord: struct address
 */
void john_jesus(info_t *lord)
{
	lord->arg = NULL;
	lord->argv = NULL;
	lord->path = NULL;
	lord->argc = 0;
}


/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int johnjesus = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (johnjesus = 0; info->argv && info->argv[johnjesus]; johnjesus++)
			;
		info->argc = johnjesus;

		replace_alias(info);
		replace_vars(info);
	}
}


/**
 * jo_yo - frees info_t struct fields
 * @bement: struct address
 * @belv: true if freeing all fields
 */
void jo_yo(info_t *bement, int belv)
{
	ffree(bement->argv);
	bement->argv = NULL;
	bement->path = NULL;
	if (belv)
	{
		if (!bement->cmd_buf)
			free(bement->arg);
		if (bement->env)
			free_list(&(bement->env));
		if (bement->history)
			free_list(&(bement->history));
		if (bement->alias)
			free_list(&(bement->alias));
		ffree(bement->environ);
		        bement->environ = NULL;
		bfree((void **)bement->cmd_buf);
		if (bement->readfd > 2)
			close(bement->readfd);
		_putchar(BUF_FLUSH);
	}
}

