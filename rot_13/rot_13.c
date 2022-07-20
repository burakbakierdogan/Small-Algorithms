/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

*/

#include <unistd.h>

void	ft_putchar13(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (c <= 'Z' - 13)
		{
			c = c + 13;
			write (1, &c, 1);
			return ;
		}
		else
		{
			c = 'A' + 12 - ('Z' - c);
			write (1, &c, 1);
			return ;
		}
	}
	if (c >= 'a' && c <= 'z')
	{
		if (c <= 'z' - 13)
		{
			c = c + 13;
			write (1, &c, 1);
			return ;
		}
		else
		{
			c = 'a' + 12 - ('z' - c);
			write (1, &c, 1);
			return ;
		}
	}
	write (1, &c, 1);
}

int	main (int ac, char *argv[])
{
	int	index;

	index = 0;
	if (ac == 2)
	{
		while (argv[1][index])
			ft_putchar13(argv[1][index++]);
	}
	write (1, "\n", 1);
}
