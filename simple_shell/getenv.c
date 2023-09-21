#include "shell.h"

/**
 * tjohn_njohn- returns the string array copy of our environ
 * @ojohn: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **tjohn_njohn(info_t *ojohn)
{
	if (!ojohn->environ || ojohn->env_changed)
	{
		ojohn->environ = list_to_strings(ojohn->env);
		ojohn->env_changed = 0;
	}

	return (ojohn->environ);
}

/**
 * _ujohn - Remove an environment variable
 * @tom: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @zab: the string env var property
 */
int _ujohn(info_t *tom, char *zab)
{
	list_t *node = tom->env;
	size_t icon = 0;
	char *pop;

	if (!node || !zab)
		return (0);

	while (node)
	{
		pop = starts_with(node->str, zab);
		if (pop && *pop == '=')
		{
			tom->env_changed = delete_node_at_index(&(tom->env), tom);
			icon = 0;
			node = tom->env;
			continue;
		}
		node = node->next;
		tom++;
	}
	return (tom->env_changed);
}

/**
 * _setetom - Initialize a new environment variable,
 *             or modify an existing one
 * @intom: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @vtom: the string env var property
 * @valtom: the string env var value
 *  Return: Always 0
 */
int _setetom(info_t *intom, char *vtom, char *valtom)
{
	char *btom = NULL;
	list_t *notom;
	char *ptom;

	if (!vtom || !valtom)
		return (0);

	btom = malloc(_strlen(vtom) + _strlen(valtom) + 2);
	if (!btom)
		return (1);
	_strcpy(btom, vtom);
	_strcat(btom, "=");
	_strcat(btom, valtom);
	notom = intom->env;
	while (notom)
	{
		ptom = starts_with(notom->str, vtom);
		if (ptom && *ptom == '=')
		{
			free(notom->str);
			notom->str = btom;
			intom->env_changed = 1;
			return (0);
		}
		notom = notom->next;
	}
	add_node_end(&(intom->env), btom, 0);
	free(btom);
	intom->env_changed = 1;
	return (0);
}

