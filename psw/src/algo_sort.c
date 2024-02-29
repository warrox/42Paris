#include "psw_lib.h"

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
void ft_sort(t_data *data)
{
	// if 3, 4, >4
	if(ft_is_sorted(data) == 1)
		exit(EXIT_SUCCESS);
	/*while(ft_is_sorted(data) != 1)
	{
		HERE IS THE MAIN LOOP TRYING TO CHECK IF STACK IS SORTED
	}*/
	if(ft_list_lenght(data->stack_a) == 3)
	{
			
		if(data->stack_a->nbr > data->stack_a->next->nbr && 
		data->stack_a->nbr > data->stack_a->next->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}

		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_sa(data);
			data->counter++;
		}
	}
	if(ft_list_lenght(data->stack_a) > 3)
		ft_pa(data);
}
