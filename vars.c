#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @inf: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *inf)
{
	int icon;
	list_t *node;
	char *pjo;

	for (icon = 0; icon < 10; icon++)
	{
		node = node_starts_with(inf->alias, inf->argv[0], '=');
		if (!node)
			return (0);
		free(inf->argv[0]);
		pjo = _strchr(node->str, '=');
		if (!pjo)
			return (0);
		pjo = _strdup(pjo + 1);
		if (!pjo)
			return (0);
		inf->argv[0] = pjo;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @inf: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *inf)
{
	int icon = 0;
	list_t *node;

	for (icon = 0; inf->argv[icon]; icon++)
	{
		if (inf->argv[icon][0] != '$' || !inf->argv[icon][1])
			continue;

		if (!_strcmp(inf->argv[icon], "$?"))
		{
			replace_string(&(inf->argv[icon]),
					_strdup(convert_number(inf->status, 10, 0)));
			continue;
		}
		if (!_strcmp(inf->argv[icon], "$$"))
		{
			replace_string(&(inf->argv[icon]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(inf->env, &inf->argv[icon][1], '=');
		if (node)
		{
			replace_string(&(inf->argv[icon]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&inf->argv[icon], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @ojo: address of old string
 * @njo: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **ojo, char *njo)
{
	free(*ojo);
	*ojo = njo;
	return (1);
}

