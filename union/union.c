/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	index;

	index = 0;
	while(s[index])
		index++;
	return (index);
}

void	ft_strjoin(char *s1, char *s2, char *dest)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (s1[index])
	{
		dest[index] = s1[index];
		index++;
	}
	while (s2[index2])
		dest[index++] = s2[index2++];
	dest[index] = '\0';
}

int	ft_is_repeat(char *dest2, char c, int size)
{
	while (size--)
		if (dest2[size] == c)
			return (1);
	return (0);
}

int main (int ac, char *argv[])
{

	int	len;
	int	index;

	index = 0;
	if (ac == 3)
	{
		char dest[ft_strlen(argv[1]) + ft_strlen(argv[2])];
		char dest2[ft_strlen(argv[1]) + ft_strlen(argv[2])];
		ft_strjoin(argv[1], argv[2], dest);
		len = ft_strlen(dest) - 1;
		while (len >= 0)
		{
			if (ft_is_repeat(dest, dest[len], len) == 0)
				dest2[index++] = dest[len];
			len--;
		}
		index--;
		while (index >= 0)
			write(1, &dest2[index--], 1);
	}
	write(1, "\n", 1);
}
