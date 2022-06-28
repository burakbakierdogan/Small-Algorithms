#include <stdio.h>

void	ft_change(char *str)
{
	str[1] = 'k';
}

int main()
{
	char str[5] = {'b', 'u', 'r', 'a','\0'};
	ft_change(str);
	printf("%s", str);

}
