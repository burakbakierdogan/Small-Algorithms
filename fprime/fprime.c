/*

Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_isprime(int nbr)
{
	int	index;

	index = 2;
	while (index < nbr)
	{
		if (nbr % index == 0)
			return (0);
		index++;
	}
	return (1);
}

int main (int ac, char *argv[])
{
	int	nbr;
	int	index;
	int	nbr2;

	index = 3;
	if (ac == 2)
	{
		nbr = atoi(argv[1]);
		if(nbr <= 0 || nbr == 1)
		{
			if (nbr <= 0)
				printf("\n");
			else printf("%d\n", 1);
			return (0);
		}
		while (nbr % 2 == 0 && nbr > 1)
		{
			printf("2");
			nbr /= 2;
			if (nbr > 1)
				printf("*");
			if (nbr <= 1)
			return (printf("\n") - 1);
		}
		nbr2 = nbr;
		while(index <= nbr2)
		{
			while (ft_isprime(index) && nbr > 1)
			{
				if (nbr % index == 0)
				{
					printf("%d", index);
					nbr /= index;
					if (nbr > 1)
						printf("*");
					else
					{
						printf("\n");
						return (0);
					}
				}
				else break;
			}
			index += 2;
		}
	}
	else printf("\n");
}
