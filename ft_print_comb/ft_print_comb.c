/*

create a function which lists all different combination of 3 different digits.
digits must be listed with 001 012 0123 ....      234 235 236 .... 789

only allowed function is write!

*/

#include <unistd.h>

void	ft_print_comb(void)
{
	int	index;
	int	index2;
	int	index3;

	index = '0';
	while (index <= '7')
	{
		index2 = index + 1;
		while (index2 <= '8')
		{
			index3 = index2 + 1;
			while (index3 <= '9')
			{
				write (1, &index, 1);
				write (1, &index2, 1);
				write (1, &index3, 1);
				index3++;
				if (index == '7' && index2 == '8' && index3 == '9' + 1)
					return ;
				write (1, ", ", 2);
			}
			index2++;
		}
		index++;
	}
}

int main (void)
{
	ft_print_comb();
	write (1, "\n", 1);
}
