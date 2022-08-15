/*

Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>


*/

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr < 10)
	{
		nbr = nbr + 48;
		write (1, &nbr, 1);
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}

int main (int ac, char *argv[])
{
	ft_putnbr(ac -1);
	write (1, "\n", 1);
}
