#include <unistd.h>
#include <stdio.h>
int     ft_strlen(const char *str)
{
	        int index;

		        index = 0;
			        while (str[index])
					                index++;
				        return (index);
}
int ft_isdigit(char c)
{
	        if (c >= '0' && c <= '9')
			                return (1);
		        return (0);
}

int     ft_atoi(const char *str)
{
	        int index;
		        int sign;
			        char ptr[ft_strlen(str)];
				        int index2;
					        int sum;
						        int mul;

							        index = 0;
								        sign = 1;
									        index2= 0;
										        sum = 0;
											        mul = 1;

												        while (str[index] <= 32 && str[index])
														                index++;
													        if (str[index] == '-' || str[index] == '+')
															        {
																	                if (str[index] == '-')
																				                        sign *= -1;
																			                index++;
																					        }
														        while (ft_isdigit(str[index]) && str[index])
																                ptr[index2++] = str[index++];
															        index2--;
																        while (index2 >= 0)
																		        {
																				                sum += (ptr[index2] - '0') * mul;
																						                mul *=10;
																								                index2--;
																										        }
																	        return (sum * sign);

}

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
int main (int ac, char *argv[])
{	
 	
	print_bits(ft_atoi(argv[1]));
	write(1,"\n",1);
}
