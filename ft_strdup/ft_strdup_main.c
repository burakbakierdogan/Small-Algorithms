#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src);

int main (int ac, char *argv[])
{
	char *str = ft_strdup(argv[1]);
	printf("%s\n",str);
	free (str);
}
