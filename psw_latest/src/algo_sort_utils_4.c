#include "psw_lib.h"

int index_lower_nbr(t_list *stack_b)
{
	long lower;
	int index;
	int r_index;
	lower = INT_MAX;
	index = 0;
	r_index = INT_MAX;
	t_list *temp = stack_b;
	while(temp != NULL)
	{
		if(temp->nbr < lower)
		{
			lower = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return(r_index);
}

int index_higher_nbr(t_list *stack_b)
{
	long higher;
	int index;
	int r_index;
	higher = INT_MIN;
	index = 0;
	r_index = INT_MAX;
	t_list *temp = stack_b;
	while(temp)
	{
		if(temp->nbr > higher)
		{
			higher = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return(r_index);
}
