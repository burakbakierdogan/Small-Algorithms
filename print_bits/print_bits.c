#include <unistd.h>
#include <stdio.h>
void print_bits(unsigned char oclet)
{
	unsigned int a = oclet;
	char	str[8] =  {'0', '0','0','0','0','0','0','0'};
	int		index;

	index = 0;
	while (a)
	{
		str[index++] = 48 +  a % 2;
		a /= 2; 
	}
	index = 7;
	while(index >= 0)
	{
		write(1, &str[index--], 1);
	}
	
}
int main ()
{
 	unsigned int a = 255;
	print_bits(a);
}
