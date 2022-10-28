#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n - The number in question.
 *
 * Return: Value of the last digit.
 */
int print_last_digit(int n)
{
	int l, p;

	l = n % 10;
	if (l <  0)
		l = -l;
	p = '0' + l;
	_putchar(p);
	return (l);
}
