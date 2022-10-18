#include "main.h"

/**
 * print_times_table - Prints the times table of the input,
 *                     starting with 0.
 * @n: The value of the times table to be printed.
 *
 */
void print_times_table(int n)
{
	int num, mult, prod;

	if (n <= 15 && n >= 0)
	{
		for (num = 0; num <= n; num++)
		{
			prod = num * mult;
			if (prod >= 100)
			{
				_putchar((prod / 100) + '0');
				_putchar(((prod / 10) % 10) + '0');
			}
			else if (prod < 100 && prod >= 10)
			{
				_putchar((prod / 10) + '0');
			}
			_putchar((prod % 10) + '0');

			if (mult == n)
				continue;
			_putchar(',');
			_putchar(' ');
			if (prod < 100)
				_putchar(' ');
			if (prod < 10)
				_putchar(' ');
		}
		_putchar('\n');
	}
}
