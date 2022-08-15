#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	struct list	*next;
	int 		nbr;
}				t_list;

t_list *ft_new(int nbr1)
{
	t_list new = malloc (sizeof(t_list));
	t_list -> nbr = nbr1;
	new -> next NULL;
	return (new);
}

int main (void)
{
	t_list *head;
	t_list *tmp;
	tmp = ft_new(42);
	head = tmp;
	tmp = ft_new(33);

	n1 = malloc(sizeof(t_list));
}
