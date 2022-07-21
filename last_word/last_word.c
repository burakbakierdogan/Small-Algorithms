/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


*/

#include <unistd.h>

int	main(int ac, char *argv[])
{
	int		index;
	int		len;
	char	buf[1000];

	index = 0;
	len = 0;
	if (ac == 2)
	{
		while (argv[1][len])
			len++;
		if (len)
			len--;
		while ((argv[1][len] == ' ' || argv[1][len] == '\t') && len >= 0)
			len--;
		while ((argv[1][len] != ' ' && argv[1][len] != '\t') && len >= 0)
				buf[index++] = argv[1][len--];
		index--;
		while (index >= 0)
			write(1, &buf[index--], 1);
	}
	write (1, "\n", 1);
}
