/*

Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>

*/

#include <unistd.h>

int	ft_isletter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' &&c <= 'z'))
		return (1);
	return (0);
}

int	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
void ft_capitalize(char c)
{
	c -= 32;
	write (1, &c, 1);
}
void ft_decapitalize(char c)
{
	c += 32;
	write (1, &c, 1);
}

int	main(int ac, char *argv[])
{
	int	index;
	int	index2;

	index = 1;
	index2 = 0;
	if (ac > 1)
	{
		while (index < ac)
		{
			while (argv[index][index2] == ' ' || argv[index][index2] == '\t' )
				write (1, &argv[index][index2++], 1);
			if (ft_isletter(argv[index][index2]))
			{
				if (ft_islower(argv[index][index2]))
					ft_capitalize(argv[index][index2++]);
				else
					write(1, &argv[index][index2++], 1);
			}
			while (argv[index][index2] && (argv[index][index2] != ' ' || argv[index][index2] != '\t'))
			{
				if (ft_isupper(argv[index][index2]) && ft_isletter(argv[index][index2]))
					ft_decapitalize(argv[index][index2++]);
				else if (argv[index][index2] != ' ' || argv[index][index2] != '\t')
					write (1, &argv[index][index2++], 1);

				while ((argv[index][index2] == ' ' || argv[index][index2] == '\t') && argv[index][index2])
				{
					write (1, &argv[index][index2++], 1);
					if (ft_isletter(argv[index][index2]) && ft_islower(argv[index][index2]))
						ft_capitalize(argv[index][index2++]);
					else if (ft_isletter(argv[index][index2]) && ft_isupper(argv[index][index2]))
						write (1, &argv[index][index2++], 1);
				}
			}
			index2 = 0;
			index++;
			write (1, "\n", 1);
		}
	}
	else
	write (1, "\n", 1);
}
