#include "psw_lib.h"

int ft_is_sorted(t_data *data)
{
	t_list *temp;
	t_list *current;
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