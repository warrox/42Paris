/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:29:48 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 09:05:23 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_cost_mediane(t_list *stack, int i, int *cost)
{
	int	med;
	int	len;

	len = ft_list_lenght(stack);
	med = len / 2;
	if (i > med)
	{
		cost[0] = len - i;
		cost[1] = DOWN;
	}
	else
	{
		cost[0] = i;
		cost[1] = UP;
	}
}

int	higher_nbr(t_list *stack_b)
{
	int		higher;
	t_list	*temp;

	higher = INT_MIN;
	temp = stack_b;
	while (temp)
	{
		if (temp->nbr > higher)
			higher = temp->nbr;
		temp = temp->next;
	}
	return (higher);
}

int	ft_simplify_cost(t_data *data)
{
	int	cost;
	int	tmp_costa;
	int	tmp_costb;

	cost = data->cost_a[0] + data->cost_b[0];
	tmp_costa = data->cost_a[0];
	tmp_costb = data->cost_b[0];
	while (data->cost_a[1] == data->cost_b[1] && (tmp_costa > 0
			&& tmp_costb > 0))
	{
		cost -= 1;
		tmp_costa -= 1;
		tmp_costb -= 1;
	}
	return (cost);
}

int	ft_lowest_cost_sa(t_data *data, t_list *stack)
{
	int	cost;

	data->cost_a[0] = 0;
	data->cost_a[1] = 0;
	data->cost_b[0] = 0;
	data->cost_b[1] = 0;
	data->index_b = 0;
	cost = 0;
	(void)stack;
	if (is_max_or_min(stack, data->stack_b) == 2 || is_max_or_min(stack,
			data->stack_b) == 1)
	{
		ft_cost_mediane(data->stack_a, data->i, data->cost_a);
		data->index_b = index_higher_nbr(data->stack_b);
		ft_cost_mediane(data->stack_b, data->index_b, data->cost_b);
	}
	else if (is_max_or_min(stack, data->stack_b) == 0)
	{
		ft_cost_mediane(data->stack_a, data->i, data->cost_a);
		data->index_b = index_middle_nbr(data);
		ft_cost_mediane(data->stack_b, data->index_b, data->cost_b);
	}
	cost = ft_simplify_cost(data);
	return (cost);
}
