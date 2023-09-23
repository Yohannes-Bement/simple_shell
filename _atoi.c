#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_john - checks if character is a delimeter
 * @john: the char to check
 * @dog: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_john(char john, char *dog)
{
	while (*dog)
		if (*dog++ == john)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _yohanes - converts a string to an integer
 * @john: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _yohanes(char *john)
{
	int icon, signjo = 1, flagjo = 0, outputjo;
	unsigned int resultjo = 0;

	for (icon = 0; john[icon] != '\0' && flagjo != 2; icon++)
	{
		if (john[icon] == '-')
			signjo *= -1;

		if (john[icon] >= '0' && john[icon] <= '9')
		{
			flagjo = 1;
			resultjo *= 10;
			resultjo += (john[icon] - '0');
		}
		else if (flagjo == 1)
			flagjo = 2;
	}

	if (signjo == -1)
		outputjo = -resultjo;
	else
		outputjo = resultjo;

	return (outputjo);
}

