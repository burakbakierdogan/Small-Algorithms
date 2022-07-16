/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_len(int nbr)
{
	int	index;
	int	number;

	index = 0;
	if (nbr < 0)
	{
		number = nbr * -1;
		index++;
	}
	number = nbr;
	while (number)
	{
		number /= 10;
		index++;
	}
	return (index);
}


char	*ft_putnbr(char *str, int len, int number)
{
	while (number && len >= 0)
	{
		str[len--] = 48 + (number % 10);
		number /= 10;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		index;
	int		number;

	len = ft_len(nbr);
	number = nbr;
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
		number = nbr * -1;
	str = (char *) malloc (len * sizeof(char));
	str[len] = '\0';
	len--;
	str = ft_putnbr(str, len, number);
	if (nbr < 0)
		str[0] = '-';
	return (str);
}

int main (void) // for test purpose
{
	int a = INT_MAX; // to get the max int number
	printf("%s\n", ft_itoa(a));
}
