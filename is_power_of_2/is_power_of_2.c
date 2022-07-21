/*

Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

*/

#include <limits.h>
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	index;

	index = 1;
	while (index < ULONG_MAX && index <= n)
	{
		if (index == n)
			return (1);
		index *= 2;
	}
	return (0);
}

int main (void) // for the test purpose
{
	int n = 1025;
	printf("%d\n" , is_power_of_2(n - 1));
}
