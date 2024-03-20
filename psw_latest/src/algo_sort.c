/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:17 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 08:22:18 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_cost(t_data *data)
{
	t_list	*temp_a;
	int		counter_cur;
	int		cur_lowest;

	temp_a = data->stack_a;
	counter_cur = 0;
	cur_lowest = INT_MAX;
	ft_data_cost_init(data);
	while (temp_a != NULL)
	{
		counter_cur = ft_lowest_cost_sa(data, temp_a);
		if (data->final_cost == 0)
			return (0);
		if (counter_cur < data->final_cost)
		{
			data->final_cost = counter_cur;
			data->f_cost_a[0] = data->cost_a[0];
			data->f_cost_a[1] = data->cost_a[1];
			data->f_cost_b[0] = data->cost_b[0];
			data->f_cost_b[1] = data->cost_b[1];
			cur_lowest = data->i;
		}
		data->i++;
		temp_a = temp_a->next;
	}
	return (cur_lowest);
}
void	ft_action(t_data *data)
{
	ft_cost(data);
	if (data->final_cost == 0)
	{
		ft_pb(data);
		return ;
	}
	ft_act_up(data);
	ft_act_down(data);
	ft_pb(data);
}

void	ft_sort_up_4(t_data *data)
{
	int	nb_ra;
	int	moy;

	ft_pb(data);
	ft_pb(data);
	while (ft_list_lenght(data->stack_a) > 3)
		ft_action(data);
	ft_sort_3(data);
	while (data->stack_b != NULL)
	{
		ft_action_a(data);
		ft_pa(data);
		if (data->stack_a->nbr == higher_nbr(data->stack_a))
			ft_ra(data);
	}
	nb_ra = push_lowest_top(data->stack_a);
	moy = ft_list_lenght(data->stack_a) / 2;
	if (nb_ra > moy)
	{
		nb_ra -= moy;
		while (nb_ra--)
			ft_rra(data);
	}
	else
		while (nb_ra--)
			ft_ra(data);
}

void	ft_sort(t_data *data)
{
	if (ft_is_sorted(data) == 1)
		exit(1);
	if (ft_list_lenght(data->stack_a) == 2)
		ft_sort_2(data);
	if (ft_list_lenght(data->stack_a) == 3)
		ft_sort_3(data);
	if (ft_list_lenght(data->stack_a) > 4)
		ft_sort_up_4(data);
	if(ft_list_lenght(data->stack_a) == 4)
	{
		while(data->stack_a->nbr != higher_nbr(data->stack_a))
			ft_ra(data);
		ft_pb(data);
		ft_sort_3(data);
		ft_pa(data);
		ft_ra(data);
	}
}
