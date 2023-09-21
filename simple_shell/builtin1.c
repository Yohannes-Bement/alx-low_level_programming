#include "shell.h"

/**
 * _yohanes - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @bement: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _yohanes(info_t *bement)
{
	print_list(bement->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *johnjesus, yohanesbement;
	int tomabint;

	johnjesus = _strchr(str, '=');
	if (!johnjesus)
		return (1);
	yohanesbement = *johnjesus;
	*johnjesus = 0;
	tomabint = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*johnjesus = yohanesbement;
	return (tomabint);
}

/**
 * set_alias - sets alias to string
 * @alutube: parameter struct
 * @asr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *alutube, char *asr)
{
	char *abl;

	abl = _strchr(asr, '=');
	if (!abl)
		return (1);
	if (!*++abl)
		return (unset_alias(alutube, asr));

	unset_alias(alutube, asr);
	return (add_node_end(&(alutube->alias), asr, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @johnjesus: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *johnjesus)
{
	char *tom = NULL, *zab = NULL;

	if (johnjesus)
	{
		tom = _strchr(johnjesus->str, '=');
		for (zab = johnjesus->str; zab <= tom; zab++)
		_putchar(*zab);
		_putchar('\'');
		_puts(tom + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _nap - mimics the alias builtin (man alias)
 * @infoJ: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _nap(info_t *infoJ)
{
	int IPAD = 0;
	char *POP = NULL;
	list_t *node = NULL;

	if (infoJ->argc == 1)
	{
		node = infoJ->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (IPAD = 1; infoJ->argv[IPAD]; IPAD++)
	{
		POP = _strchr(infoJ->argv[IPAD], '=');
		if (POP)
			set_alias(infoJ, infoJ->argv[IPAD]);
		else
			print_alias(node_starts_with(infoJ->alias, infoJ->argv[IPAD], '='));
	}

	return (0);
}

