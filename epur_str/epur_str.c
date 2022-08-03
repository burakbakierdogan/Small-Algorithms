/*

Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>

*/

#include <unistd.h>

int main (int ac, char *argv[])
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
		while (argv[1][index2] == ' ' || argv[1][index2] == '\t')
			index2--;
		while ((argv[1][index] == ' ' || argv[1][index] == '\t') && argv[1][index])
			index++;
		while (index <= index2)
		{
			if (argv[1][index] == ' ' || argv[1][index] == '\t')
			{
				write(1, &argv[1][index], 1);
				while ((argv[1][index] == ' ' || argv[1][index] == '\t') && argv[1][index])
					index++;
			}
			else
			write (1, &argv[1][index++], 1);
		}
	}
	write (1, "\n", 1);
}
