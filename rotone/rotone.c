/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/

#include <unistd.h>

int	main(int ac, char *argv[])
{
	int	index;

	index = 0;
	if (ac == 2)
	{
		while (argv[1][index])
		{
			if ((argv[1][index] >= 'a' && argv[1][index] <= 'z') || (argv[1][index] >= 'A' && argv[1][index] <= 'Z'))
			{
				if (argv[1][index] == 'z' || argv[1][index] == 'Z')
				{
					if (argv[1][index] == 'z')
						argv[1][index] = 'a';
					else if (argv[1][index] == 'Z')
						argv[1][index] = 'A';
				}
				else	argv[1][index] = *(argv[1] + index) + 1;
			}
			write (1, &argv[1][index++], 1);
		}
	}
	write(1, "\n", 1);
}
