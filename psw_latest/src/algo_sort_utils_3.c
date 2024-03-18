/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:09 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/18 16:46:38 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_push_b_to_a(t_data *data)
{
	int index;
	index = 0;
	ft_data_cost_init(data);
	
	if(data->stack_b->nbr < lower_nbr(data->stack_a))
	{
		index = index_higher_nbr(data->stack_a);
		ft_printf("%d is lower at index : %d\n",data->stack_b->nbr ,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
	}
	else if(data->stack_b->nbr > higher_nbr(data->stack_a))
	{
		index = index_higher_nbr(data->stack_a);
		ft_printf("%d is higher at index : %d\n",data->stack_b->nbr ,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
	}
	else
	{
		index = index_middle_nbr_a(data);
		ft_printf("%d is middle at index : %d\n",data->stack_b->nbr ,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
	}
		
	
}
void ft_action_a(t_data *data)
{
	if(data->cost_a[1] == UP)
	{
		while(data->cost_a[0] > 0)
		{
			ft_ra(data);
			data->cost_a[0]--;
		}
		
	}
	if(data->cost_a[1] == DOWN)
	{
		while(data->cost_a[0] > 0)
		{
			ft_rra(data);
			data->cost_a[0]--;
		}
	}
}
void ft_act_up(t_data *data)
{
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
}

void ft_act_down(t_data *data)
{
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
}

