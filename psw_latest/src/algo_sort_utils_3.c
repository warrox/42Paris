/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:09 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 14:12:00 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_cost_a(t_data *data)
{
	int		index;
	t_list	*stack;

	stack = data->stack_b;
	index = 0;
	ft_data_cost_init(data);
	if (is_max_or_min_a(stack, data->stack_a) == 1)
	{
		index = index_lower_nbr(data->stack_a);
		ft_cost_mediane(data->stack_a, index, data->cost_a);
	}
	if (is_max_or_min_a(stack, data->stack_a) == 2)
	{
		index = index_lower_nbr(data->stack_a);
		ft_cost_mediane(data->stack_a, index, data->cost_a);
	}
	if (is_max_or_min_a(stack, data->stack_a) == 0)
	{
		index = index_middle_nbr_a(data);
		ft_cost_mediane(data->stack_a, index, data->cost_a);
	}
}

void	ft_action_a(t_data *data)
{
	ft_cost_a(data);
	if (data->cost_a[1] == UP)
	{
		while (data->cost_a[0] > 0)
		{
			ft_ra(data, 1);
			data->cost_a[0]--;
		}
	}
	if (data->cost_a[1] == DOWN)
	{
		while (data->cost_a[0] > 0)
		{
			ft_rra(data, 1);
			data->cost_a[0]--;
		}
	}
}

void	ft_act_up(t_data *data)
{
	if (data->f_cost_a[1] == UP && data->f_cost_b[1] == UP)
	{
		while (data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if (data->f_cost_a[1] == UP)
	{
		while (data->f_cost_a[0] > 0)
		{
			ft_ra(data, 1);
			data->f_cost_a[0]--;
		}
	}
	if (data->f_cost_b[1] == UP)
	{
		while (data->f_cost_b[0] > 0)
		{
			ft_rb(data, 1);
			data->f_cost_b[0]--;
		}
	}
}

void	ft_act_down(t_data *data)
{
	if (data->f_cost_a[1] == DOWN && data->f_cost_b[1] == DOWN)
	{
		while (data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rrr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if (data->f_cost_a[1] == DOWN)
	{
		while (data->f_cost_a[0] > 0)
		{
			ft_rra(data, 1);
			data->f_cost_a[0]--;
		}
	}
	if (data->f_cost_b[1] == DOWN)
	{
		while (data->f_cost_b[0] > 0)
		{
			ft_rrb(data, 1);
			data->f_cost_b[0]--;
		}
	}
}
