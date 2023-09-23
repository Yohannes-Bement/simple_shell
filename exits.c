#include "shell.h"

/**
 **_s - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_s(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_kak - concatenates two strings
 *@destj: the first string
 *@srcj: the second string
 *@nj: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_kak(char *destj, char *srcj, int nj)
{
	int ij, jj;
	char *sj = destj;

	ij = 0;
	jj = 0;
	while (destj[ij] != '\0')
		ij++;
	while (srcj[jj] != '\0' && jj < nj)
	{
		destj[ij] = srcj[jj];
		ij++;
		jj++;
	}
	if (jj < nj)
		destj[ij] = '\0';
	return (sj);
}

/**
 **_zab - locates a character in a string
 *@jo: the string to be parsed
 *@tom: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_zab(char *jo, char tom)
{
	do {
		if (*jo == tom)
			return (jo);
	} while (*jo++ != '\0');

	return (NULL);
}

