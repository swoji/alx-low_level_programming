#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - print if the number is positive, negative, or zero
 *
 * return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%d is positive\n", n);
	else if (n < 0)
	        print("%d is negative\n", n);
	else (n==0)
		print("%d is zero\n",n);

	return (0);
i}
