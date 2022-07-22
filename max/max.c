/*

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/
#include <stdio.h>

int	max(int	*tab, unsigned int len)
{
	int	index;
	int	len2;
	int	total;

	total = len;
	len--;
	index = 0;
	len2 = len;
	if (!tab || len < 0)
		return (0);
	while (len >= 0)
	{
		while (len2 >= 0)
		{
			if (tab[len] >= tab[len2])
				index++;
			if (index == total)
				return (tab[len]);
			len2--;
		}
		len2 = total - 1;
		len--;
		index = 0;
	}
}

int	main(void) // for the test purpose
{
	int ar[124] = {99999998, -99999, 99999, 9999990, 99999};
	int a = max(ar, 5);
	printf ("%d\n", a);
}
