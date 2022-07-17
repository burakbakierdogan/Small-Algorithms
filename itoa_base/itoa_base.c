/*

Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:

char	*ft_itoa_base(int value, int base);

*/

#include <stdlib.h>
#include <stdio.h>

int	ft_len(int value, int base)
{
	int	len;

	len = 0;
	if (base == 10)
		if (value < 0)
			len++;
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;
	int		nbr;

	if (value < 0 && base != 10)
		return (NULL);
	if (value == 0)
		return ("0");
	if (value == -2147483648)
		return ("-2147483648");
	nbr = value;
	if (value < 0)
		value *= -1;
	len = ft_len(nbr, base);
	str = (char *) malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (base <= 10)
		{
			str[len] = (48 + (value % base));
			value = value / base;
			len--;
			if (nbr < 0 && len < 0)
				str[len + 1] = '-';
		}
		if (base >= 11 && base <= 16)
		{
			str[len] = (48 + (value % base));
			if (value % base >= 10)
				str[len] = ('A' + ((value % base) - 10));
			len--;
			value = value / base;
		}
	}
	return (str);
}

int main (void) // for the test purpose
{
	printf("%s\n", ft_itoa_base(255, 16));
}
