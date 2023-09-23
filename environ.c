#include "shell.h"

/**
 * _my - prints the current environment
 * @i: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _my(info_t *i)
{
	print_list_str(i->env);
	return (0);
}

/**
 * _get - gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_get(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _zab - Initialize a new environment variable,
 *             or modify an existing one
 * @nat: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _zab(info_t *nat)
{
	if (nat->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(nat, nat->argv[1], nat->argv[2]))
		return (0);
	return (1);
}

/**
 * _tom - Remove an environment variable
 * @nap: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _tom(info_t *nap)
{
	int ij;

	if (nap->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (ij = 1; ij <= nap->argc; ij++)
		_unsetenv(nap, nap->argv[ij]);

	return (0);
}

/**
 * jesus_lord_list - populates env linked list
 * @bki: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int jesus_lord_list(info_t *bki)
{
	list_t *n = NULL;
	size_t ij;

	for (ij = 0; environ[ij]; ij++)
		add_node_end(&n, environ[ij], 0);
	bki->env = n;
	return (0);
}

