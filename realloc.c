#include "shell.h"

/**
 * _johnyo - fills memory with a constant byte
 * @son: the pointer to the memory area
 * @boy: the byte to fill *s with
 * @nop: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_johnyo(char *son, char boy, unsigned int nop)
{
	unsigned int icon;

	for (icon = 0; icon < nop; icon++)
		son[icon] = boy;
	return (son);
}

/**
 * tom - frees a string of strings
 * @ppjohn: string of strings
 */
void tom(char **ppjohn)
{
	char **ajohn = ppjohn;

	if (!ppjohn)
		return;
	while (*ppjohn)
		free(*ppjohn++);
	free(ajohn);
}

/**
 * _nat - reallocates a block of memory
 * @ptjo: pointer to previous malloc'ated block
 * @old_jo: byte size of previous block
 * @new_jo: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_nat(void *ptjo, unsigned int old_jo, unsigned int new_jo)
{
	char *p;

	if (!ptjo)
		return (malloc(new_jo));
	if (!new_jo)
		return (free(ptjo), NULL);
	if (new_jo == old_jo)
		return (ptjo);

	p = malloc(new_jo);
	if (!p)
		return (NULL);

	old_jo = old_jo < new_jo ? old_jo : new_jo;
	while (old_jo--)
		p[old_jo] = ((char *)ptjo)[old_jo];
	free(ptjo);
	return (p);
}

