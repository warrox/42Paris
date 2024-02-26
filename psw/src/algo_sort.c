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
	if(ft_list_lenght(data->stack_a) > 3)
		ft_push_a_to_b(data);
}
