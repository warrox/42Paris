#include "psw_lib.h"
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