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
	const list_t *temp = NULL;

	i = 0;
	temp = h;
	while (temp != NULL)
	{
		if (temp->str ==  NULL)
		{
			printf("[0] (nil)\n");
		}
		else
			printf("[%d] %s\n", temp->len, temp->str);
		temp  = temp->next;
		i++;
	}
	return (i);
}
