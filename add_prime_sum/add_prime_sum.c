/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

#include <unistd.h>

int	ft_is_prime(int c)
{
	int	index;

	if (c == 2)
		return (1);
	if (c == 0 || c == 1)
		return (0);
	index = 2;
	while (index < c)
	{
		if (c % index == 0)
			return (0);
		index++;
	}
	return (1);
}
void	ft_itoa(int nbr)
{

	if (nbr < 10)
	{
		nbr = nbr + 48;
		write (1, &nbr, 1);
		return ;
	}
	ft_itoa(nbr / 10);
	ft_itoa(nbr % 10);
}
int	ft_atoi(char *str)
{
	int	index;
	int	sum;
	int	base;

	sum = 0;
	base = 1;
	index = 0;
	while (str[index])
		index++;
	index--;
	while (index >= 0)
	{
		sum += (str[index--] - 48) * base;
		base *= 10;
	}
	return (sum);
}

int main(int ac, char *argv[])
{
	int	nbr;
	int	index;
	int	sum;

	index = 2;
	if (ac == 2)
	{
		nbr = ft_atoi(argv[1]);
		if (argv[1][0] == '-')
		{
			write (1, "0\n", 2);
			return (0);
		}
		while (index <= nbr)
		{
			if (ft_is_prime(index))
				sum += index;
			index++;
		}
		ft_itoa(sum);
		write (1, "\n", 1);
	}
	else
	write (1, "0\n", 2);
}
