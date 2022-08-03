/*

Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>


*/

#include <unistd.h>

int main(int ac, char *argv[])
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	if (ac == 2)
	{
		while (argv[1][index2])
			index2++;
		index2--;
		while(argv[1][index2] == ' ' || argv[1][index2] == '\t')
			index2--;
		while (argv[1][index] && (argv[1][index2] == ' ' || argv[1][index2] == '\t'))
			index++;
		while (index <= index2 && argv[1][index])
		{
			if ((argv[1][index] == ' ' || argv[1][index] == '\t'))
			{
				write (1, "   ", 3);
				while ((argv[1][index] == ' ' || argv[1][index] == '\t') && argv[1][index])
					index++;
			}
			write (1, &argv[1][index++], 1);
		}
	}
	write (1, "\n", 1);
}
