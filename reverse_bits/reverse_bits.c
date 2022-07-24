/*

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100

 */

#include <stdio.h>

unsigned char	ft_reverse_bits(unsigned char octet)
{
	char				arr[8] = {48,48,48,48,48,48,48,48};
	int					index;
	unsigned char		sum;
	int					b;

	sum = 0;
	index = 0;
	b = 1;
	while (octet)
	{
		arr[index++] = (octet % 2) + 48;
		octet /= 2;
	}
	index = 7;
	while (index >= 0)
	{
		sum += (arr[index--] - 48) * b;
		b *= 2;
	}
	return (sum);
}

int main (void) // for the test purpose
{
	int a = ft_reverse_bits(1);
	printf("%d\n", a);
}
