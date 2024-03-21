/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:10:59 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 10:11:23 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int	index_middle_nbr_a(t_data *data)
{
	t_list	*stack_b_tmp;
	t_list	*stack_a;

	data->f_index = -1;
	data->best_dif = INT_MAX;
	stack_b_tmp = data->stack_b;
	stack_a = data->stack_a;
	data->nbr = find_nbr(stack_b_tmp, 0);
	data->index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->nbr > data->nbr)
		{
			data->dif = stack_a->nbr - data->nbr;
			if (data->dif < data->best_dif)
			{
				data->best_dif = data->dif;
				data->f_index = data->index;
			}
		}
		stack_a = stack_a->next;
		data->index++;
	}
	return (data->f_index);
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
