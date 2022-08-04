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

int	ft_atoi_base(char *str, int str_base)
{

	int		index;
	int		index2;
	int		sign;
	char	arr[20];
	int		sum;
	int		b;

	index  = 0;
	index2 = 0;
	sign = 1;
	sum = 0;
	b = 1;


	while (str[index] <= 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	if (str_base < 11)
	{
		while (str[index] && (str[index] >= '0' && str[index] < 48 + str_base))
			arr[index2++] = str[index++];
	}
	else if (str_base >= 11 && str_base <= 16)
	{
		while (str[index] && ((str[index] >= '0' && str[index] <= '9') || (str[index] >= 'a' && str[index] <= 'a' + str_base - 10)
			|| (str[index] >= '0' && str[index] <= '9')  || (str[index] >= 'A' && str[index] <= 'A' + str_base - 10)))
			arr[index2++] = str[index++];

	}
	/*arr[index2] = '\0';
	printf("array = %s\n", arr);
	*/

	index2--;

	if (index2)
	{

		if (str_base > 1 && str_base < 11)
		{
			while (index2 >= 0)
			{
				sum += (arr[index2--] - 48) * b;
				b *= str_base;
			}
		}
		else if (str_base >= 11 && str_base <= 16)
		{
			while (index2 >= 0)
			{
				if (arr[index2] >= '0' && arr[index2] <= '9')
				{
					sum += (arr[index2] - 48) * b;
					b *= str_base;
				}
				else if (arr[index2] >= 'a' && str[index2] <= 'f')
				{
					sum += (arr[index2] - 'a' + 10) * b;
					b *= str_base;
				}
				else if (arr[index2] >= 'A' && arr[index2] <= 'F')
				{
					sum += (arr[index2] - 'A' + 10) * b;
					b *= str_base;
				}
				index2--;
			}
		}
	}
	return (sum * sign);
}

int main ()
{
	int a = ft_atoi_base("ABCD", 11);
	printf("%d\n", a);
}
