#include "shell.h"

/**
 * _king - returns the length of a string
 * @sjohn: the string whose length to check
 *
 * Return: integer length of string
 */
int _king(char *sjohn)
{
	int ijohn = 0;

	if (!sjohn)
		return (0);

	while (*sjohn++)
		ijohn++;
	return (ijohn);
}

/**
 * _jtn - performs lexicogarphic comparison of two strangs.
 * @s1jo: the first strang
 * @s2jo: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _jtn(char *s1jo, char *s2jo)
{
	while (*s1jo && *s2jo)
	{
		if (*s1jo != *s2jo)
			return (*s1jo - *s2jo);
		s1jo++;
		s2jo++;
	}
	if (*s1jo == *s2jo)
		return (0);
	else
		return (*s1jo < *s2jo ? -1 : 1);
}

/**
 * starts_wjohn - checks if needle starts with haystack
 * @hjohn: string to search
 * @njohn: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_wjohn(const char *hjohn, const char *njohn)
{
	while (*njohn)
		if (*njohn++ != *hjohn++)
			return (NULL);
	return ((char *)hjohn);
}

/**
 * _john - concatenates two strings
 * @dest: the destination buffer
 * @sjohn: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_john(char *dest, char *sjohn)
{
	char *rjohn = dest;

	while (*dest)
		dest++;
	while (*sjohn)
		*dest++ = *sjohn++;
	*dest = *sjohn;
	return (rjohn);
}

