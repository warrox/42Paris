/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:17 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/15 13:19:36 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
#include <stdio.h>
#include <stdlib.h>


void ft_data_cost_init(t_data *data)
{
	data->final_cost = INT_MAX;
	data->f_cost_a[0] = INT_MAX;
	data->f_cost_a[1] = INT_MAX;
	data->f_cost_b[0] = INT_MAX;
	data->f_cost_b[1] = INT_MAX;
	data->i = 0;
}
int	ft_cost(t_data *data)
{
	t_list *temp_a = data->stack_a;
	int counter_cur = 0;
	int cur_lowest = INT_MAX;
	ft_data_cost_init(data);
	while(temp_a != NULL)
	{
		counter_cur = ft_lowest_cost_sa(data,temp_a);
		if(data->final_cost == 0)
			return(0);
		if (counter_cur < data->final_cost)
		{
			data->final_cost = counter_cur;
			data->f_cost_a[0] = data->cost_a[0];
			data->f_cost_a[1] = data->cost_a[1];
			data->f_cost_b[0] = data->cost_b[0];
			data->f_cost_b[1] = data->cost_b[1];
			ft_printf("final cost : %d, nbr choosed : %d\n",data->final_cost,temp_a->nbr);
			cur_lowest = data->i;
		}
		data->i++;
		temp_a = temp_a->next;
	}
	return(cur_lowest);
}
void ft_action(t_data *data)
{
	ft_cost(data);
	if(data->final_cost == 0)
	{
		ft_pb(data);
		return;
	}
	if(data->f_cost_a[1] == UP && data->f_cost_b[1] == UP)
	{
		while(data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if(data->f_cost_a[1] == UP)
	{
		while(data->f_cost_a[0] > 0)
		{
			ft_ra(data);
			data->f_cost_a[0]--;
		}
	}
	if(data->f_cost_b[1] == UP)
	{
		while(data->f_cost_b[0] > 0)
		{
			ft_rb(data);
			data->f_cost_b[0]--;
		}
	}
	
	if(data->f_cost_a[1] == DOWN && data->f_cost_b[1] == DOWN)
	{
		while(data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rrr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if(data->f_cost_a[1] == DOWN)
	{
		while(data->f_cost_a[0] > 0)
		{
			ft_rra(data);
			data->f_cost_a[0]--;
		}
	}
	if(data->f_cost_b[1] == DOWN)
	{
		while(data->f_cost_b[0] > 0)
		{
			ft_rrb(data);
			data->f_cost_b[0]--;
		}
	}
	ft_pb(data);
}

void ft_doner(t_data *data)
{
	ft_pb(data);
	ft_pb(data);
	while(ft_list_lenght(data->stack_a) > 3)
	{
		ft_action(data);
		//stack_a_visualizer(data->stack_a);
		ft_printf("---------\n");
		stack_b_visualizer(data->stack_b);
		stack_a_visualizer(data->stack_a);
	}
	if(ft_list_lenght(data->stack_a)== 3)
		ft_sort_3(data);
}




void ft_sort(t_data *data)
{
	if(ft_is_sorted(data) == 1)
		exit(1);
	if(ft_list_lenght(data->stack_a) == 2)
		ft_sort_2(data);
	if(ft_list_lenght(data->stack_a) == 3)
		ft_sort_3(data);
	if(ft_list_lenght(data->stack_a) > 4)
		ft_doner(data);
	// if(ft_list_lenght(data->stack_a) == 4)
	// 	ft_sort_4(data);
}
