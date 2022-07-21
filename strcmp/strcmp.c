/*

Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);

*/


#include <string.h>
#include <stdio.h>



int	ft_strcmp(char *s1, char *s2)
{
	int	index;
	int	ret;
	int	len;
	int	len2;

	index = 0;
	ret = 0;
	len = 0;
	len2 = 0;
	while (s1[len])
		len++;
	while (s2[len2])
		len2++;
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			ret = s1[index] - s2[index];
		index++;
	}
	if (index < len)
		ret = 1;
	if (index < len2)
		ret = -1;
	if (ret < 0)
		ret = -1;
	if (ret > 0)
		ret = 1;
	return (ret);
}

int main (void) // for the test purpose
{
	int a = strcmp("burak", "burak");
	int b = ft_strcmp("burak", "burak");
	printf("%d %d\n",a ,b);
}

