#include "psw_lib.h"
#include <stdio.h>

int ft_cost_mediane_a(t_list *stack, int i)
{
	int length;
	
	length = 0;
	length = ft_list_lenght(stack);
	if(length / 2 < i)
		return(2); // rr
	else
		return(1); // r
}
int higher_nbr(t_list *stack_b)
{
	int higher;
	higher = 0;
	t_list *temp = stack_b;
	while(temp->next)
	{
		if(higher < temp->nbr)
			higher = temp->nbr;
		temp = temp->next;
	}
	return(higher);
}
int lower_nbr(t_list *stack_b)
{
	int lower;
	lower = 0;
	t_list *temp = stack_b;
	while(temp->next)
	{
		if(lower < temp->nbr)
			lower = temp->nbr;
		temp = temp->next;
	}
	return(lower);
}
int is_max_or_min(t_list *stack_a, t_list *stack_b)
{
	
	if(stack_a->nbr < lower_nbr(stack_b))
		return(1);
	if(stack_a->nbr > higher_nbr(stack_b))
		return(2);

	return(0);
}

int ft_lowest_cost_sa(t_list *stack_a, t_list *stack_b)
{
	// ici tu check toutes les conditions et tu renvoies le lowest cost
	t_list *temp_a;
	t_list *temp_b;
	int cost;
	cost = 0;

	temp_b = stack_b;
	temp_a = stack_a;

	if(is_max_or_min(temp_a, temp_b)== 2)
	{
		if(ft_cost_mediane_a(temp_a))
		while(temp_b->next != NULL)
		{
			// ft_mediane_b + ft_mediane_a
			temp_b = temp_b->next;
		}
	}
	if(is_max_or_min(temp_a, temp_b)== 1)
	{
		while(temp_b->next != NULL && temp_a->nbr > temp_b->nbr)
		{
			cost++;
			temp_b = temp_b->next;
		}
	}
	if(is_max_or_min(temp_a,temp_b) == 0)
	{
		while(temp_b->next != NULL && temp_a->nbr > temp_b->nbr)
		{
			cost++;
			temp_b = temp_b->next;
		}
	}
	return(cost);
}

//Check wich element in stack a are costless and return the index of this element
int	ft_cost(t_data *data)
{
	t_list *temp = data->stack_a;
	t_list *stack_b;
	int counter_cur;
	int counter_next;

	counter_cur = 0;
	counter_next = 0;
	stack_b = data->stack_b;
	data->i = 0;
	// ici faire une fonction qui renvoie le less cost de tous les next de b
	counter_cur = ft_lowest_cost_sa(temp,stack_b);
	temp = temp->next;
	while(temp->next != NULL)
	{
		stack_a_visualizer(temp);
		counter_next = ft_lowest_cost_sa(temp,stack_b);
		if(counter_cur > counter_next && (counter_next - data->i) < counter_cur) // redondant ?
		{
			counter_cur = counter_next;
			data->i++;
		}
		temp = temp->next;
	}
	return(data->i);
}

void ft_doner(t_data *data)
{
	int index;
	t_list *temp;
	temp = data->stack_a;
	index = 0;
	data->counter = 0;
	ft_pb(data);
	ft_pb(data);
	while(data->stack_a->next)
	{
		index = ft_cost(data); //element qui coute le moins a placer dans stack B
		while(index) // place le pointeur sur element a push 
		{
			temp = temp->next;
			index--;
		}
		// ft_merguez() execute le push avec les instructions donner.
		data->stack_a = data->stack_a->next; // check si ca casse pas ta chaine
	}
	// second part push tout vers A 
}




void ft_sort(t_data *data)
{
	// if 3, 4, >4
	if(ft_is_sorted(data) == 1)
		exit(EXIT_SUCCESS);
	/*while(ft_is_sorted(data) != 1)
	{
		HERE IS THE MAIN LOOP TRYING TO CHECK IF STACK IS SORTED
	}*/
	if(ft_list_lenght(data->stack_a) == 2)
		ft_sort_2(data);
	if(ft_list_lenght(data->stack_a) == 3)
		ft_sort_3(data);
	if(ft_list_lenght(data->stack_a) > 4)
		ft_doner(data);
	// if(ft_list_lenght(data->stack_a) == 4)
	// 	ft_sort_4(data);
	// if(ft_list_lenght(data->stack_a) > 4)
	// 	ft_pa(data);
}
