/*

Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $

*/

#include <unistd.h>

int	main(int ac, char *argv[])
{
	int	index;

	index = 0;
	if (ac == 4)
	{
		if (argv[3][1] || argv[2][1])
		{
			write (1, "\n", 1);
			return (999999);
		}
		while (argv[1][index])
		{
			if (argv[1][index] == argv[2][0])
			{
				write (1, &argv[3][0], 1);
				index++;
			}
			else	write (1, &argv[1][index++], 1);
		}
	}
	write (1, "\n", 1);
}
