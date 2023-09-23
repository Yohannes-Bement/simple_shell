#include "shell.h"

/**
 * john_len - determines length of linked list
 * @hj: pointer to first node
 *
 * Return: size of list
 */
size_t john_len(const list_t *hj)
{
	size_t m = 0;

	while (hj)
	{
		hj = hj->next;
		m++;
	}
	return (m);
}

/**
 * list_nat_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_nat_strings(list_t *head)
{
	list_t *node = head;
	size_t icon = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !icon)
		return (NULL);
	strs = malloc(sizeof(char *) * (icon + 1));
	if (!strs)
		return (NULL);
	for (icon = 0; node; node = node->next, icon++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < icon; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[icon] = str;
	}
	strs[icon] = NULL;
	return (strs);
}


/**
 * pri_l - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t pri_l(const list_t *h)
{
	size_t icon = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		icon++;
	}
	return (icon);
}

/**
 * node_tom_with - returns node whose string starts with prefix
 * @no: pointer to list head
 * @pref: string to match
 * @d: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_tom_with(list_t *no, char *pref, char d)
{
	char *p = NULL;

	while (no)
	{
		p = starts_with(no->str, pref);
		if (p && ((d == -1) || (*p == d)))
			return (no);
		no = no->next;
	}
	return (NULL);
}

/**
 * get_john_index - gets the index of a node
 * @tom: pointer to list head
 * @n: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_john_index(list_t *tom, list_t *n)
{
	size_t t = 0;

	while (tom)
	{
		if (tom == n)
			return (t);
		tom = tom->next;
		t++;
	}
	return (-1);
}

