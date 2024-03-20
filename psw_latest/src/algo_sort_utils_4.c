#include "psw_lib.h"

int	index_middle_nbr_a(t_data *data)
{
	int		nbr;
	int		index;
	int		f_index;
	int		dif;
	int		best_dif;
	t_list	*stack_b_tmp;
	t_list	*stack_a;

	f_index = -1;
	best_dif = INT_MAX;
	stack_b_tmp = data->stack_b;
	stack_a = data->stack_a;
	nbr = find_nbr(stack_b_tmp, 0);
	index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->nbr > nbr)
		{
			dif = stack_a->nbr - nbr;
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
int	is_max_or_min_a(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->nbr < lower_nbr(stack_b))
		return (1);
	if (stack_a->nbr > higher_nbr(stack_b))
		return (2);
	return (0);
}
int	index_lower_nbr(t_list *stack_b)
{
	long	lower;
	int		index;
	int		r_index;
	t_list	*temp;

	lower = INT_MAX;
	index = 0;
	r_index = INT_MAX;
	temp = stack_b;
	while (temp != NULL)
	{
		if (temp->nbr < lower)
		{
			lower = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (r_index);
}

int	index_higher_nbr(t_list *stack_b)
{
	long	higher;
	int		index;
	int		r_index;
	t_list	*temp;

	higher = INT_MIN;
	index = 0;
	r_index = INT_MAX;
	temp = stack_b;
	while (temp)
	{
		if (temp->nbr > higher)
		{
			higher = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (r_index);
}
