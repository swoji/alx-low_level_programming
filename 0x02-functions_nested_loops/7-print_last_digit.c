#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n - The number in question.
 *
 * Return: Value of the last digit.
 */
int print_last_digit(int n)
{
	int i;
	i = n % 10;
	
	if (i > 0)
	
	_putchar((n % 10) + '0');

	return (n % 10);
}
