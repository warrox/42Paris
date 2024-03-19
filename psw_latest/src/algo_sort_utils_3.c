/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:52:09 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/19 17:53:40 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
int is_max_or_min_a(t_list *stack_a, t_list *stack_b)
{
	
	if(stack_a->nbr < lower_nbr(stack_b))
		return(1);
	if(stack_a->nbr > higher_nbr(stack_b))
		return(2);
	return(0);
}


int index_middle_nbr_a(t_data *data)
{
    int nbr;
    int index;
    int f_index = -1;
    int dif;
    int best_dif = INT_MAX;
	t_list *stack_b_tmp = data->stack_b;
    t_list *stack_a = data->stack_a;
    nbr = find_nbr(stack_b_tmp, 0);
	ft_printf("NBR : %d\n",nbr);
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
void 	ft_cost_a(t_data *data)
{
	int index;
	t_list *stack;
	stack = data->stack_b;
	index = 0;
	ft_data_cost_init(data);
	if(is_max_or_min_a(stack,data->stack_a) == 1)
	{
		index = index_lower_nbr(data->stack_a);
		printf("%ld*index low= %d\n",data->stack_b->nbr,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
	}
	if(is_max_or_min_a(stack,data->stack_a) == 2)
	{
		index = index_lower_nbr(data->stack_a);
		printf("%ld*index high= %d\n", data->stack_b->nbr,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
		ft_printf("cost[0] : %d, cost[1] : %d\n",data->cost_a[0],data->cost_a[1]);
	}
	if(is_max_or_min_a(stack,data->stack_a) == 0)
	{
		index = index_middle_nbr_a(data);
		printf("%ld*index = %d\n", data->stack_b->nbr,index);
		ft_cost_mediane(data->stack_a,index,data->cost_a);
	}
}
void ft_action_a(t_data *data)
{
	ft_cost_a(data);
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


