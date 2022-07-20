/*

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>

*/

#include <unistd.h>


void	ft_putnbr(int c)
{
	if (c < 10)
	{
		c = 48 + c;
		write (1, &c, 1);
		return;
	}
	ft_putnbr(c / 10);
	ft_putnbr(c % 10);
}

int main (void)
{
	int	index;

	index = 1;
	while (index <= 100)
	{
		if (index % 3 == 0 && index % 5)
			write (1, "fizz", 4);
		else if (index % 3 && index % 5 == 0)
			write (1, "buzz", 4);
		else if (!(index % 3) && !(index % 5))
			write(1, "fizzbuzz", 8);
		else	ft_putnbr(index);
		write (1, "\n", 1);
		index++;
	}

}
