#include "main.h"

/**
 * _strcpy - Copies a string pointed to by @src, including the
 *           terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */
char *_strcpy(char *dest, char *src)
{
	int index = 0;
	int n;

	while (src[index] != '\0')
	{
		index++;
	}

	n = 0;
	while (n < index && src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}

	n = n;
	while (n <= index)
	{
		dest[n] = '\0';
		n++;
	}
	return (dest);
}
