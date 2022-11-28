#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	unsigned int i;
	const list_t *tmp = NULL;

	i = 0;
	tmp = h;
	while (tmp != NULL)
	{
		if (tmp->str ==  NULL)
		{
			printf("[0] (nil)\n");
		}
		else
			printf("[%d] %s\n", tmp->len, tmp->str);
		tmp = tmp->next;
		i++;
	}
	return (i);
}