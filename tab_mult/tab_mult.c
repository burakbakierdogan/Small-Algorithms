/*

Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>

*/

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	index;
	int	sum;
	int	base;
	int sign;

	index = 0;
	sum = 0;
	base = 1;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while(str[index++]);
	index -=2;
	while (index >= 0)
	{
		sum += (str[index--] -48) * base;
		base *=10;
		if (str[index] == '-' || str[index] == '+')
			break;
	}
	return (sum * sign);
}

int	ft_len(int nbr)
{
	int	index;

	index = 0;
	while (nbr)
	{
		nbr /= 10;
		index++;
	}
	return (index);
}

void	ft_itoa(int nbr, char *str)
{
	int		len;

	len = ft_len(nbr);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (48 + (nbr % 10));
		len--;
		nbr /=10;
	}
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}
int main (int ac, char *argv[])
{
	int		nbr;
	int		index;
	char	str[100];
	char	str2[100];

	index = 1;
	if (ac == 2)
	{
		nbr = ft_atoi(argv[1]);
		ft_itoa(nbr, str);
		while (index <= 9)
		{
			ft_putchar(48 + index);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putstr(str);
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_itoa(index * nbr, str2);
			ft_putstr(str2);
			write (1, "\n", 1);
			index++;
		}
	}
	else
	write (1, "\n", 1);
}
