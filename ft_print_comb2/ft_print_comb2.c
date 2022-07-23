/*

write a function which displays all different combination which displays all different combination 00 99
here is the expected output:
00 01, 00 02, 00 03, ......... 97 98, 97 99, 98 99$
first block and second block must always be different. if first block is 45 then second block cant be 45 it has to be bigger than 45
because smaller numbers of this combination is already printed.

only allowed function is write.

*/


#include <unistd.h>

void	ft_itoa(int nbr)
{
	char	str[2];
	int		index;

	index = 1;
	if (nbr < 10)
	{
		str[0] = '0';
		str[1] = 48 + (nbr % 10);
		write (1, &str[0], 1);
		write (1, &str[1], 1);
		return ;
	}

	while (index >= 0)
	{
		str[index] = (nbr % 10) + 48;
		nbr /= 10;
		index--;
	}
	index = 0;
	while (index <= 1)
		write (1, &str[index++], 1);
}

void	ft_print_comb2(void)
{
	int	index;
	int	index1;

	index = 0;
	while (index <= 98)
	{
		index1 = index + 1;
		while (index1 <= 99)
		{
			ft_itoa(index);
			write (1, " ", 1);
			ft_itoa(index1);
			if (index == 98 && index1 == 99)
				return ;
			write(1, ", ", 2);
			index1++;
		}
		index++;
	}
}
int	main(void) // for the test purpose
{
	ft_print_comb2();
}
