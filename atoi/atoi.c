/* ssignment name  : ft_atoi
 Expected files   : ft_atoi.c
 Allowed functions: None
 --------------------------------------------------------------------------------

 Write a function that converts the string argument str to an integer (type int)
	and returns it.

	It works much like the standard atoi(const char *str) function, see the man.

	Your function must be declared as follows:

	int	ft_atoi(const char *str);

*/

#include <stdio.h>
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
		mul *=10;
		index2--;
	}
	return (sum * sign);
	
}
int main (int ac, char *argv[])
{
	int a =	ft_atoi(argv[1]);
	printf("%d\n", a);
}
