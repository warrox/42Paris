/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:17 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/19 18:03:28 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_cost(t_data *data)
{
	t_list *temp_a = data->stack_a;
	int counter_cur = 0;
	int cur_lowest = INT_MAX;
	ft_data_cost_init(data);
	while(temp_a != NULL)
	{
		counter_cur = ft_lowest_cost_sa(data,temp_a);
		//printf("i = %d, cost_a[0] : %d, cost_b[0] : %d len = %d\n", data->i,data->cost_a[0],data->cost_b[0], ft_list_lenght(data->stack_a));
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
	ft_act_up(data);
	ft_act_down(data);
	ft_pb(data);
}

void ft_sort_up_4(t_data *data)
{
	//int i = 0;
	ft_pb(data);
	ft_pb(data);
	while(ft_list_lenght(data->stack_a) > 3)
	{
		//printf("ACTION = %d\n", i++);
		ft_action(data);
		// stack_a_visualizer(data->stack_a);
		// ft_printf("---------\n");
		// stack_b_visualizer(data->stack_b);
		// stack_a_visualizer(data->stack_a);
	}
	stack_a_visualizer(data->stack_a);
	ft_printf("---HERE---\n");
	ft_sort_3(data);
	stack_a_visualizer(data->stack_a);
	stack_b_visualizer(data->stack_b);
	while(data->stack_b != NULL)
	{
		ft_action_a(data);
		ft_pa(data);
		if(data->stack_a->nbr == higher_nbr(data->stack_a))
			ft_ra(data);
		ft_printf("BIM\n");
		stack_a_visualizer(data->stack_a);
	}
	int nb_ra = push_lowest_top(data->stack_a);
	int moy = ft_list_lenght(data->stack_a) / 2;
	printf("ra = %d\n", nb_ra);
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




void ft_sort(t_data *data)
{
	if(ft_is_sorted(data) == 1)
		exit(1);
	if(ft_list_lenght(data->stack_a) == 2)
		ft_sort_2(data);
	if(ft_list_lenght(data->stack_a) == 3)
		ft_sort_3(data);
	if(ft_list_lenght(data->stack_a) > 4)
		ft_sort_up_4(data);
	
	// if(ft_list_lenght(data->stack_a) == 4)
	// 	ft_sort_4(data);
}
