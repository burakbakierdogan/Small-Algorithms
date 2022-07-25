/*

Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100

*/

#include <stdio.h>

void	ft_swap(char *arr)
{
	int		index;
	char	arr1[4];
	char	arr2[4];
	int		index2;

	index = -1;
	index2 = 0;
	while (index++ <= 2)
		arr1[index] = arr[index];
	while (index <= 7)
		arr2[index2++] = arr[index++];
	index = -1;
	index2 = 0;
	while (index++ <= 2)
		arr[index] = arr2[index];
	while (index <= 7)
		arr[index++] = arr1[index2++];
}

unsigned char swap_bits(unsigned char octet)
{
	int					index;
	char				arr[8] = {48,48,48,48,48,48,48,48};
	int					index2;
	int					b;
	unsigned char		sum;

	index = 7;
	b = 1;
	sum = 0;
	while (octet)
	{
		arr[index--] = (octet % 2) + 48;
		octet /=2;
	}
	index = 7;
	ft_swap(arr);
	while (index >= 0)
	{
		sum += (arr[index--] - 48) * b;
		b *= 2;
	}
	return (sum);
}

int	main(void) // for the test purpose
{
	printf("%d\n",swap_bits(65));
}
