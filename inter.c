/*
   Assignment name  : inter
   Expected files   : inter.c
   Allowed functions: write
   --------------------------------------------------------------------------------
   Write a program that takes two strings and displays, without doubles, the
   characters that appear in both strings, in the order they appear in the first
   one.
   The display will be followed by a \n.
   If the number of arguments is not 2, the program displays \n.
Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int	ft_strlen(char *s1)
{
	int	index = 0;

	while (s1[index] != '\0')
		index++;
	return (index);
}

int	ft_compare(char *s1, char s2, int size)
{
	int index;
	int total;
	int index2;

	index = 0;
	total = 0;
	while (index < size)
	{
		if (s1[index] == s2)
			total++;
		index++;
	}
	return (total);

}

void ft_rev(char *s1, int size)
{
	char temp[size];
	int index = 0;
	int total = size;
	while (index <= total)
	{
		temp[index] = s1[size];
		index++;
		size--;
	}
	index = 0;
	while (index <= total)
	{
		s1[index] = temp[index];
		index++;
	}
}
int main (int ac, char **argv)
{
	char	str[ft_strlen(argv[1])];
	int len;
	int index;
	int index2 = 0;

	index = 0;
	len = ft_strlen(argv[1]);
	if (ac == 3)
	{
		while (len >= 0)
		{
			if (ft_compare(argv[1], argv[1][len], len) == 0)
			{
				str[index] =  argv[1][len];
				index++;
			}
			len--;
		}
		ft_rev(str, (index - 1) );

		int size = ft_strlen(argv[2]);
		while(index)
		{
			if (ft_compare(argv[2], str[index2], size))
				write(1, &str[index2], 1);
			index2++;
			index--;
		}
		write(1, "\n", 1);
	}
	else
	write(1, "\n", 1);
}
