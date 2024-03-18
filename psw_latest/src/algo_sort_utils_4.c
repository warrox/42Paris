#include "psw_lib.h"

int index_middle_nbr_a(t_data *data)
{
    int nbr;
    int index;
    int f_index = -1;
    int dif;
    int best_dif = INT_MAX;
	t_list *stack_b_tmp = data->stack_b;
    t_list *stack_a = data->stack_a;
    ft_printf("valeur de i : %d\n",data->i);
	nbr = find_nbr(stack_b_tmp, data->i);
    index = 0;
    while (stack_a != NULL)
    {
        if (nbr > stack_a->nbr)
        {
            dif = nbr - stack_a->nbr;
            if (dif < best_dif)
            {
                best_dif = dif;
                f_index = index;
            }
        }
        stack_a = stack_a->next;
        index++;
    }
    return (f_index);
}


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