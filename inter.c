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

int	ft_strlen(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
void	ft_strrev(char *s1, int size)
{
	char	temp[size];
	int		total;


	int index = 0;
	total = size;
	while (size >= 0)
	{
		temp[index] = s1[size];
		index++;
		size--;
	}
	index = 0;
	while (index < total + 1 )
	{
		s1[index] = temp[index];
		index++;
	}
}
int	ft_compare(char *s1, char s2, int size)
{
	int	index;
	int	total;

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


int	main(int ac, char *argv[])
{
	char	str[ft_strlen(argv[1]) + ft_strlen(argv[2])];
	int		index;
	int		index2;
	int		total;

	index = ft_strlen(argv[1]);
	index2 = 0;
	total = 0;


	if (ac == 3)
	{
			while (index >= 0)
		{
			if (ft_compare(argv[1], argv[1][index], index) == 0)
				{
					str[index2] = argv[1][index];
					index2++;
					total++;
				}
			index--;
		}
	ft_strrev(str, total);
	index = 0;
	int k = ft_strlen(argv[2]);
	while (total)
	{
		if (ft_compare(argv[2], str[index], k))
		{
			write(1, &str[index], 1);
		}
		index++;
		total--;
	}
	}
	write(1, "\n", 1);
}
