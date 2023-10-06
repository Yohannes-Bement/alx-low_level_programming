#include "shell.h"

/**
 * _holly - prints the current environment
 * @sofya: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _holly(info_t *sofya)
{
	print_list_str(sofya->env);
	return (0);
}

/**
 * _is - gets the value of an environ variable
 * @dava: Structure containing potential arguments. Used to maintain
 * @esgnt: env var name
 *
 * Return: the value
 */
char *_is(info_t *dava, const char *esgnt)
{
	list_t *node = dava->env;
	char *kak;

	while (node)
	{
		kak = starts_with(node->str, esgnt);
		if (kak && *kak)
			return (kak);
		node = node->next;
	}
	return (NULL);
}

/**
 * _zablon - Initialize a new environment variable,
 *             or modify an existing one
 * @mkoy: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _zablon(info_t *mkoy)
{
	if (mkoy->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(mkoy, mkoy->argv[1], mkoy->argv[2]))
		return (0);
	return (1);
}

/**
 * _GOD - Remove an environment variable
 * @holly: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _GOD(info_t *holly)
{
	int sprit;

	if (holly->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (sprit = 1; sprit <= holly->argc; sprit++)
		_unsetenv(holly, holly->argv[sprit]);

	return (0);
}

/**
 * jesus_is_lord - populates env linked list
 * @nati: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int jesus_is_lord(info_t *nati)
{
	list_t *node = NULL;
	size_t tom;

	for (tom = 0; environ[tom]; tom++)
		add_node_end(&node, environ[tom], 0);
	nati->env = node;
	return (0);
}

