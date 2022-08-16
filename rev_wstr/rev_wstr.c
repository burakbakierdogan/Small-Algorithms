/*

Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>


*/

#include <unistd.h>
#include <stdlib.h>

typedef struct rev
{
	char	*ptr;
	int		ret;
}			sret; //struct return

int	ft_len(char *str)
{
	int	index;

	index = 0;
	while(str[index] && (str[index] != ' ' || str[index] != '\t'))
		index++;
	return (index);
}

sret ft_new(char *str)
{
	char	*s;
	sret	a;
	int	index;

	index = 0;
	s = malloc (ft_len(str) * sizeof(char));
	if (!s)
	{
		a.ptr = NULL;
		return (a);
	}
	while (str[index] && (str[index] != ' ' && str[index] != '\t'))
	{
		s[index] = str[index];
		index++;

	}
	s[index] = '\0';
	a.ptr = s;
	a.ret = index;
	return (a);
}

void	ft_write(char *str, int i)
{
	int	index;

	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
	if (i != 0)
		write(1, " ", 1);
}

int main (int ac, char *argv[])
{
	int		index;
	int		len;
	char	**ptr;
	int		i;
	int		j;
	sret	a;

	index = 0;
	len = 0;
	i = 0;
	if (ac == 2)
	{
		while (argv[1][len])
			len++;
		len--;
		while (argv[1][len] == ' ' || argv[1][len] == '\t')
			len--;
		ptr = (char **) malloc(len * sizeof(char *));
		if (!ptr)
			return (0);
		while ((argv[1][index] == ' ' || argv[1][index] == '\t') && argv[1][index])
			index++;
		while (index <= len)
		{
			a = ft_new(&argv[1][index]);
			index += a.ret;
			ptr[i++] = a.ptr;
			while ((argv[1][index] == ' ' || argv[1][index] == '\t') && index <= len)
				index++;
		}
		i--;
		j = i;
		while (i >= 0)
		{
			ft_write(ptr[i], i);
			i--;
		}
		while (j >= 0)
			free((ptr[j--]));
		free(ptr);
	}
	write (1, "\n", 1);
}
