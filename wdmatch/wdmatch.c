/*Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
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

int	ft_match(char *s1, char c, int index2)
{
	while (s1[index2])
	{
		if (s1[index2] == c)
		{
			index2++;
			return (index2);
		}
		else
		index2++;
	}
	return (0);
}

int main (int ac, char *argv[])
{
	int	index;
	int	index2;
	int len;
	int total;

	index2 = 0;
	index = 0;
	total = 0;

	if (ac == 3)
	{
		len = ft_strlen(argv[1]);
		while (argv[1][index])
		{
			if (ft_match(argv[2], argv[1][index], index2) && index2 <= ft_strlen(argv[2]))
				{
					index2 = ft_match(argv[2], argv[1][index], index2);
					total++;
				}
			index++;
		}
		index = 0;
		if (total == len)
		{
			while (argv[1][index])
				write(1, &argv[1][index++], 1);
		}
	}
	write (1, "\n", 1);
}
