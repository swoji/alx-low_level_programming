#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints the last digit of a randomly generated num and whether it is greater than 5, less than 6, or zero
 *
 * Return: ALways 0
 */
int main(void)
{
	int n;
	int i;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	i = n % 10;

	if (i > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, i);
	}
	else if (i==0)
	{
		printf("Last digit of %d is %d and is 0\n", n, i);
	}
	else
	{
		print(Lastdigit of %d is %d and is less than 6 andnot 0\n", n, i);
	}
	return (0);

}
