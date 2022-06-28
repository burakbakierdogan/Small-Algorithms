#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s1)
{
	int index = 0;
	while (s1[index] != '\0')
		index++;
	return (index);
}

int main (int ac, char *argv[])
{
	printf("%c", argv[1][ft_strlen(argv[1]) - 1]);
}
