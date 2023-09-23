#include "shell.h"

/**
 * cow_lan - initializes info_t struct
 * @top: struct address
 */
void cow_lan(info_t *top)
{
	top->arg = NULL;
	top->argv = NULL;
	top->path = NULL;
	top->argc = 0;
}

/**
 * tom_abint - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void tom_abint(info_t *info, char **av)
{
	int i = 0;

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
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * son_king - frees info_t struct fields
 * @in: struct address
 * @a: true if freeing all fields
 */
void son_king(info_t *in, int a)
{
	ffree(in->argv);
	in->argv = NULL;
	in->path = NULL;
	if (a)
	{
		if (!in->cmd_buf)
			free(in->arg);
		if (in->env)
			free_list(&(in->env));
		if (in->history)
			free_list(&(in->history));
		if (in->alias)
			free_list(&(in->alias));
		ffree(in->environ);
			in->environ = NULL;
		bfree((void **)in->cmd_buf);
		if (in->readfd > 2)
			close(in->readfd);
		_putchar(BUF_FLUSH);
	}
}

