/*

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct new
{
	char	*ptr;
	int		i;
}			ret;


ret	ft_new(char *str)
{
	int	index;
	char *new;
	ret burak;
	index = 0;

	new = malloc (1000);
	while (str[index] && (str[index] != ' ' &&  str[index] != '\t' && str[index] != '\n'))
	{
		new[index] = str[index];
		index++;
	}

	new[index] = '\0';
	burak.ptr = new;
	burak.i = index + 1;
	return (burak);
}

char	**ft_split(char *str)
{
	int	index;
	int	index2;
	ret burak;

	char **newstr;
	newstr = malloc (1000 * sizeof (char *));

	index = 0;
	index2 = 0;
	while (str[index] <= 32 && str[index] == '\n' && str[index])
		index++;
	if (str[index])
	{
		burak = ft_new(str + index);
		index += burak.i;
		newstr[index2++] = burak.ptr;
	}
	while (str[index])
	{
		if (str[index] != ' ' && str[index] != '\t' && str[index] != '\n')
		{
			burak = ft_new(str + index);
			newstr[index2++] = burak.ptr;
			index += burak.i;
		}
		else
		index++;
	}
	newstr[index2] = NULL;
	return (newstr);
}

int main (void) //for the test pupose
{
	char **str;
	str = ft_split("burak baki erdogan awdaw  	kjfkr rkjkrjgl   ");
	printf("%s\n", *(str+ 6));
}
