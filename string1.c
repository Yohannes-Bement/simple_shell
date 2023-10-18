#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *nap;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
        nap = malloc(sizeof(char) * (length + 1));
	if (!nap)
		return (NULL);
	for (length++; length--;)
		nap[length] = *--str;
	return (nap);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int tom = 0;

	if (!str)
		return;
	while (str[tom] != '\0')
	{
		_putchar(str[tom]);
		tom++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int john;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || john >= WRITE_BUF_SIZE)
	{
		write(1, buf, john);
		john = 0;
	}
	if (c != BUF_FLUSH)
		buf[john++] = c;
	return (1);
}

