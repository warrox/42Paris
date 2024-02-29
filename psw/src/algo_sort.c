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
}
void	ft_sort_2(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
}
void	ft_sort_4(t_data *data) // do not work with 1 4 3 2
{
	//[1][2][4][3]
		//RA
	//[2][4][3][1]
		//RA
	//[4][3][1][2]
		//RA
	//[3][1][2][4]
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
	if(ft_list_lenght(data->stack_a) == 4)
		ft_sort_4(data);
	if(ft_list_lenght(data->stack_a) > 4)
		ft_pa(data);
}
