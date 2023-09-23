#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
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
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @nojo: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *nojo)
{
	char *pjo = NULL, *ajo = NULL;

	if (nojo)
	{
		pjo = _strchr(nojo->str, '=');
		for (ajo = nojo->str; ajo <= pjo; ajo++)
		_putchar(*ajo);
		_putchar('\'');
		_puts(pjo + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _jo - mimics the alias builtin (man alias)
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _jo(info_t *inf)
{
	int ijo = 0;
	char *pjo = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (ijo = 1; inf->argv[ijo]; ijo++)
	{
		pjo = _strchr(inf->argv[ijo], '=');
		if (pjo)
			set_alias(inf, inf->argv[ijo]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[ijo], '='));
	}

	return (0);
}

