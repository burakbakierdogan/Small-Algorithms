/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>
#include <limits.h>

char ft_c_convert(char c)
{
	if (c == 'a')
		return ('A');
	if (c == 'b')
		return ('B');
	if (c == 'c')
		return ('C');
	if (c == 'd')
		return ('D');
	if (c == 'e')
		return ('E');
	if (c == 'f')
		return ('F');
	return (c);
}
int	ft_int_convert(char c)
{

	c = ft_c_convert(c);

	if (c >= 48 && c < 58)
		return (c - 48);
	if (c == 'A')
		return (10);
	if (c == 'B')
		return (11);
	if (c == 'C')
		return (12);
	if (c == 'D')
		return (13);
	if (c == 'E')
		return (14);
	if (c == 'F')
		return (15);
	return (0);
}

int	ft_isdigit(char c, int str_base)
{
	c = ft_c_convert(c);
	if (str_base <= 10)
	{
		if (c >= 48 && c < 48 + str_base)
			return (1);
		else
			return (0);
	}
	if (str_base == 11)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c == 'A')
			return (1);
		else
			return (0);
	}
	if (str_base == 12)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c >= 'A' && c <= 'B')
			return (1);
		else
			return (0);
	}
	if (str_base == 13)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c >= 'A' && c <= 'C')
			return (1);
		else
			return (0);
	}
	if (str_base == 14)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c >= 'A' && c <= 'D')
			return (1);
		else
			return (0);
	}
	if (str_base == 15)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c >= 'A' && c <= 'E')
			return (1);
		else
			return (0);
	}
	if (str_base == 16)
	{
		if (c >= 48 && c < 58)
			return (1);
		else if (c >= 'A' && c <= 'F')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		index;
	int		index2;
	int		sign;
	int		sum;
	char	ptr[40];
	int		b;

	index = 0;
	sign = 1;
	index2 = 0;
	sum = 0;
	b = 1;
	if (str_base <= 1)
		return (0);
	while (str[index] <= 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(str[index], str_base) && str[index])
		ptr[index2++] = str[index++];
	index2--;
	while (index2 >= 0)
	{
		sum += ft_int_convert(ptr[index2--]) * b;
		b *= str_base;
		if (sum > INT_MAX || sum < 0)
			return (-1);
	}
	return (sum * sign);
}

int main(void) //main function for the testing!//
{
	printf("%d\n",ft_atoi_base("ABCDEF", 16));
}
