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

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int	ft_base(int nbr)
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

char *ft_itoa(int nbr)
{
	int number;
	char *str;
	int	base;


	number = nbr;
	base = 0;
	if (nbr == 0)
		return ("0");
	if (nbr == -2147483648)
		return ("-2147483648");
	str = malloc (100);
	if (number < 0)
	{
		number *= -1;
		str[0] = '-';
		base += 1;
	}
	base += ft_base(number);
	str[base--] = '\0';
	while (base >= 0 && number)
	{
		str[base] = (number % 10) + '0';
		number /= 10;
		base--;
	}
	return (str);
}
int main () // for the test purpose
{
	printf("%s\n", ft_itoa(-2147483648));
}
