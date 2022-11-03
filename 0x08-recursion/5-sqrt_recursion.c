#include "main.h"

/**
 * sqrt_check - checks for the square root of i
 * @j: The number to test for the square root of @i
 * @i: number to find sqrt of
 *
 * Return: -1 or sqrt of i
 */
int sqrt_check(int j, int i)
{
	if (j * j == i)
		return (j);
	if (j * j > i)
		return (-1);
	return (sqrt_check(j + 1, i));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 *
 * Return: natural square root or -1
*/
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (sqrt_check(1, n));
}
