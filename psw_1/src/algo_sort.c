#include "psw_lib.h"
#include <stdio.h>

int ft_is_sorted(t_data *data)
{
	s_list *temp;
	s_list *current;
	current = data->stack_a;
	temp = data->stack_a->next;
	while(current && temp)
	{
		if(current->nbr > temp->nbr)
			return(0);
		temp = temp->next;
		current = current->next;
	}
	return(1);
}
void ft_sort_3(t_data *data)
{
	
	while(ft_is_sorted(data) != 1)
	{
		if(data->stack_a->nbr > data->stack_a->next->nbr && 
		data->stack_a->nbr > data->stack_a->next->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		else if (data->stack_a->nbr < data->stack_a->next->nbr && 
		data->stack_a->nbr > data->stack_a->next->next->nbr)
		{
			ft_rra(data);
			data->counter++;
		}

		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_sa(data);
			data->counter++;
		}
		if(data->stack_a->next->nbr > data->stack_a->next->next->nbr)
		{
			ft_rra(data);
			data->counter++;
		}
	}
	
}
void	ft_sort_2(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
}
void	ft_sort_4(t_data *data) // do not work with 1 4 3 2 // maj : ca va pas te servir
{
	// mi
	
	while(ft_is_sorted(data)!= 1) // not working
	{
		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		else if(data->stack_a->nbr < data->stack_a->next->nbr &&
		data->stack_a->nbr < data->stack_a->next->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_sa(data);
			data->counter++;
		}
		if(data->counter == 4)
		{
			ft_ra(data);
			data->counter++;
		}
		printf("DATA COUNTER : %d\n",data->counter);
	}
}
int higher_nbr(s_list *stack_b)
{
	int higher;
	higher = 0;
	s_list *temp = stack_b;
	while(temp->next)
	{
		if(higher < temp->nbr)
			higher = temp->nbr;
		temp = temp->next;
	}
	return(higher);
}
int lower_nbr(s_list *stack_b)
{
	int lower;
	lower = 0;
	s_list *temp = stack_b;
	while(temp->next)
	{
		if(lower < temp->nbr)
			lower = temp->nbr;
		temp = temp->next;
	}
	return(lower);
}
int is_max_or_min(s_list *stack_a, s_list *stack_b)
{
	
	if(stack_a->nbr < lower_nbr(stack_b))
		return(1);
	if(stack_a->nbr > higher_nbr(stack_b))
		return(2);

	return(0);
}
void ft_doner(t_data *data)
{
	//1 : first : pb x 2
	
	//int lowest_count;
	ft_pb(data);
	ft_pb(data);
	while(data->stack_a)
	{
		if(is_max_or_min(data->stack_a, data->stack_b)== 1)
		{
			// push to the right place
		}
		else if(is_max_or_min(data->stack_a, data->stack_b)== 2)
		{
			// push to the right place
		}
		else
		{
			// is middle
		}
		data->stack_a = data->stack_a->next;
		// func to do 2
		// 2 :determinate if the current element to push is <min or >max or a middle numbers
	}
	//3 : puis calcul du cout pour chaque element
	//4 : Push
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
