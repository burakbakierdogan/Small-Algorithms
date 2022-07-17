/*

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/

#include <unistd.h>

int	ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int index;
	int sign;
	char ptr[ft_strlen(str)];
	int index2;
	int sum;
	int mul;

	index = 0;
	sign = 1;
	index2= 0;
	sum = 0;
	mul = 1;

	while (str[index] <= 32 && str[index])
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9' && str[index])
		ptr[index2++] = str[index++];
	index2--;
	while (index2 >= 0)
	{
		sum += (ptr[index2] - '0') * mul;
		mul *= 10;
		index2--;
	}
	return (sum * sign);
}

int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 16)
	{
		len = 2;
		return (len);
	}
	while (nbr)
	{
		nbr = nbr/16;
		len++;
	}
	return (len);
}

int main (int ac, char *argv[])
{
	int		nbr;
	int		len;
	char	str[20];
	int		index;

	if (ac == 2)
	{
		nbr = ft_atoi(argv[1]);
		if (nbr < 0)
		{
			write (1, "\n", 1);
			return (0);
		}
		len = ft_len(nbr);
		index = len;
		str[len] = '\0';
		len--;
		while (len >= 0 && nbr >= 15)
		{

			str[len] = (nbr % 16) + 48;
			if ((nbr % 16) > 9)
				str[len] = (nbr % 16) - 10 + 97;
			len--;
			if (nbr < 16)
				break;
			nbr = nbr / 16;
		}
		if (nbr < 16)
	{
		if (nbr < 10)
			str[len] = 48 + nbr;
		else
		str[len] = 97 + (nbr - 10);
	}
	while (len < index)
		write(1, &str[len++], 1);
	}
	write (1, "\n", 1);
}

