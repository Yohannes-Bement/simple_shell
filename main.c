#include "shell.h"

/**
 * john - entry point
 * @ba: arg count
 * @bb: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int john(int ba, char **bb)
{
	info_t info[] = { INFO_INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (f)
			: "r" (f));

	if (ba == 2)
	{
		f = open(bb[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(bb[0]);
				_eputs(": 0: Can't open ");
				_eputs(bb[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = f;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, bb);
	return (EXIT_SUCCESS);
}

