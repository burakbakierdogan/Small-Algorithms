#include <stdarg.h>
#include <stdio.h>

int	ft_sum(int args, ...)
{
	va_list	ap;
	int		sum;
	int	index;

	sum = 0;
	index = 0;
	va_start(ap, args);
	while (index++ < args)
		sum += va_arg(ap, int);
	va_end(ap);
	return (sum);
}

int main(void)
{
	int a = ft_sum(5, 1, 2, 3,4,5, 223,12123 ,12312, 123);
	printf("%d\n", a);
}
