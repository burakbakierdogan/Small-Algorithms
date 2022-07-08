/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
 */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int index;

	index = 0;

	while (src[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
		int	index;
		char	*str;

		str = (char *) malloc (sizeof(char) * ft_strlen(src) + 1);
		if (!str)
			return (NULL);
		index = 0;
		while (src[index])
		{
			str[index] = src[index];
			index++;
		}
		str[index] = '\0';
		return (str);
}
