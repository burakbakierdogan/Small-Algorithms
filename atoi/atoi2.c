#include <unistd.h>
#include <stdio.h>

int 	escapechar(const char *w)
{
	int k;
	
	k = 0;
	while(w[k] <= 32 && w[k] != '\0')
	   k++;
	return (k);
}
int 	ft_atoi(const char *str)
{
	int b;
	int sum;
	int s;
	int index;
	int neg;
	char ptr[20];

	neg = 1;
	index = 0;
	s = escapechar(str);
	if(str[s] == '-' || str[s] == '+')
	{
		if(str[s] == '-')
		{
			neg = -1;
		}
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9' && str[s])
	{
	   	ptr[index++] = str[s++];
	}
		index--;
	b = 1;
	sum = 0;
	while(index >= 0)
	{
		sum += ptr[index] - '0' * b;
		b *= 10;
		index--;
	}
	return(sum * neg);
}
int main ()
{	
	const char *ss;
	ss = "    12324";
	printf(" : %d\n",ft_atoi("   -213132"));
}
	


			


		

		

	
