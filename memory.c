#include "shell.h"

/**
 * joyo - frees a pointer and NULLs the address
 * @pap: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int joyo(void **pap)
{
	if (pap && *pap)
	{
		free(*pap);
		*pap = NULL;
		return (1);
	}
	return (0);
}

