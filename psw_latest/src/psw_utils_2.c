#include "psw_lib.h"
#include <stdio.h>

void ft_pb(t_data *data)
{
	if(!data->stack_a)
		return;
    t_list *first_a = NULL;
	if(data && data->stack_a)
	{
		first_a = data->stack_a;
		data->stack_a = data->stack_a->next;
		first_a->next = NULL;
		ft_lstadd_front(&data->stack_b,first_a);
	}
	ft_printf("pb\n");
}

void ft_pa(t_data *data)
{
    if(!data->stack_b)
		return;
	t_list *first_b = NULL;
	if(data && data->stack_b)
	{
		first_b = data->stack_b;
		data->stack_b = data->stack_b->next;
		first_b->next = NULL;
		ft_lstadd_front(&data->stack_a,first_b);
	}
}


void display_error(void)
{
	write(1,"Error\n",6);
}

int is_not_null(char *str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	if(i == 0)
		return(1);
	return(0);
}

void stack_a_visualizer(t_list *stack_a)
{
	t_list *copy;
	copy = stack_a;
	if(!copy)
		return;
	printf("Stack A\n");
	while(copy)
	{
		printf("|%ld|\n",copy->nbr);
		copy = copy->next;
	}
}
void stack_b_visualizer(t_list *stack_b)
{
	t_list *copy;
	copy = stack_b;
	if(!copy)
		return;
	printf("Stack B\n");
	while(copy)
	{
		printf("|%ld|\n",copy->nbr);
		copy = copy->next;
	}
}
int		is_lst_double_nb(t_list *lst)
{
	t_list *temp;
	t_list *current;
	current = lst;
	int check_nbr;
	while(current->next)
	{
		temp = current;
		check_nbr = temp->nbr;
		while(temp->next)
		{
			if(check_nbr == temp->next->nbr)
				return(-1);
			temp = temp->next;
		}	
		current = current->next;
	}	
	return(0);
}
