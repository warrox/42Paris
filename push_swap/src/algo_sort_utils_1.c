/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:27:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 09:01:42 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int	lower_nbr(t_list *stack_b)
{
	int		lower;
	t_list	*temp;

	lower = INT_MAX;
	temp = stack_b;
	while (temp)
	{
		if (temp->nbr < lower)
			lower = temp->nbr;
		temp = temp->next;
	}
	return (lower);
}

int	is_max_or_min(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->nbr < lower_nbr(stack_b))
		return (1);
	if (stack_a->nbr > higher_nbr(stack_b))
		return (2);
	return (0);
}

int	find_nbr(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack && i < index)
	{
		stack = stack->next;
		i++;
	}
	return (stack->nbr);
}

int	index_middle_nbr(t_data *data)
{
	t_list	*stack_a_tmp;
	t_list	*stack_b;

	data->f_index = -1;
	data->best_dif = INT_MAX;
	stack_a_tmp = data->stack_a;
	stack_b = data->stack_b;
	data->nbr = find_nbr(stack_a_tmp, data->i);
	data->index = 0;
	while (stack_b != NULL)
	{
		if (data->nbr > stack_b->nbr)
		{
			data->dif = data->nbr - stack_b->nbr;
			if (data->dif < data->best_dif)
			{
				data->best_dif = data->dif;
				data->f_index = data->index;
			}
		}
		stack_b = stack_b->next;
		data->index++;
	}
	return (data->f_index);
}
