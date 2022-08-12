#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	struct list *next;
	int nbr;
}t_list;


int main (void)
{
	t_list *burak;
	t_list *baki;
	t_list *erdogan;

	burak = malloc (sizeof (t_list));
	baki = malloc (sizeof (t_list));
	erdogan = malloc (sizeof (t_list));
	burak -> next = baki;
	baki -> next = erdogan;
	baki -> next -> nbr = 3;
	burak -> nbr = 45;
	burak -> next -> nbr = 98;
	printf("%d-%d-%d\n",burak->nbr,baki->nbr, erdogan -> nbr);


}
/*
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/
