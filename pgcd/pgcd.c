/*

Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$

*/

#include <unistd.h>
#include <stdlib.h>

int	ft_smaller(int nbr, int nbr2)
{
	if (nbr <= nbr2)
		return (nbr);
	return (nbr2);
}

int	ft_putnbr(int nbr)
{
	if (nbr < 10)
	{
		nbr = nbr + 48;
		write (1, &nbr, 1);
		write (1, "\n", 1);
		return (0);
	}
	ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
	return (0);
}

int main(int ac, char *argv[])
{
	int	nbr;
	int	nbr2;
	int	index;

	if (ac == 3)
	{
		nbr = atoi(argv[1]);
		nbr2 = atoi(argv[2]);
		if (nbr <= 0 || nbr2 <= 0)
		{
			write (1, "\n", 1);
			return (0);
		}
		index = ft_smaller(nbr, nbr2);
		while(index > 0)
		{
			if (nbr % index == 0 && nbr2 % index == 0)
				return (ft_putnbr(index));
			index--;
		}
	}
	else write(1, "\n", 1);
}
