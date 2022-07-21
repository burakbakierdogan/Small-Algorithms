/*

Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

*/
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(char *s1, const  char *reject)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (s1[index])
	{
		while (reject[index2])
		{
			if (s1[index] == reject[index2])
				return (index);
			index2++;
		}
		index++;
		index2 = 0;
	}
	return (index);
}

int	main(void) // for test purpose
{
	int	a = strcspn("burak", "adrgr");
	int b = ft_strcspn("burak", "adrgr");
	printf("%d-%d\n", a, b);
}
