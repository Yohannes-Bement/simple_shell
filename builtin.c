#include "shell.h"

/**
 * _johnjesus - exits the shell
 * @zab: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _johnjesus(info_t *zab)
{
	int jo;

	if (zab->argv[1]) /* If there is an exit arguement */
	{
		jo = _erratoi(zab->argv[1]);
		if (jo == -1)
		{
			zab->status = 2;
			print_error(zab, "Illegal number: ");
			_eputs(zab->argv[1]);
			_eputchar('\n');
			return (1);
		}
		zab->err_num = _erratoi(zab->argv[1]);
		return (-2);
	}
	zab->err_num = -1;
	return (-2);
}

/**
 * _nap - changes the current directory of the process
 * @moky: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _nap(info_t *moky)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!moky->argv[1])
	{
		dir = _getenv(moky, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(moky, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(moky->argv[1], "-") == 0)
	{
		if (!_getenv(moky, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(moky, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(moky, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(moky->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(moky, "can't cd to ");
		_eputs(moky->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(moky, "OLDPWD", _getenv(moky, "PWD="));
		_setenv(moky, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _john - changes the current directory of the process
 * @tom: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _john(info_t *tom)
{
	char **ar_ar;

	ar_ar = tom->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*ar_ar); /* temp att_unused workaround */
	return (0);
}

