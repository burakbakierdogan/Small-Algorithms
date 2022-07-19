/*

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/

#include <unistd.h>

void ft_putchar_mirror(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (c <= 'N')
		{
			c =('Z' - (c - 'A'));
			write (1, &c, 1);
		}
		else if (c >= 'M' && c <= 'Z')
		{
			c = ( 'A' + ('Z' - c));
			write (1, &c, 1);
		}
	}
	else if (c >= 'a' && c <= 'z')
	{
		if (c <= 'n')
		{
			c = ('z' - (c - 'a'));
			write (1, &c, 1);
		}
		else if (c >= 'm' && c <= 'z')
		{
			c = ( 'a' + ('z' - c));
			write (1, &c, 1);
		}
	}
	else
		write (1, &c, 1);
}

int main (int ac, char *argv[])
{
	int	index;

	index = 0;
	if (ac == 2)
	{
		while (argv[1][index])
			ft_putchar_mirror(argv[1][index++]);
	}
	write (1, "\n", 1);
}
