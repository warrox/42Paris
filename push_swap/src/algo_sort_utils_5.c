/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:01:56 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/22 14:11:02 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	tmp = NULL;
}

void	ft_data_cost_init(t_data *data)
{
	data->final_cost = INT_MAX;
	data->f_cost_a[0] = INT_MAX;
	data->f_cost_a[1] = INT_MAX;
	data->f_cost_b[0] = INT_MAX;
	data->f_cost_b[1] = INT_MAX;
	data->i = 0;
}

int	push_lowest_top(t_list *a)
{
	t_list	*tmp;
	int		lowest;
	int		i;
	int		index;

	tmp = a;
	lowest = INT_MAX;
	i = 0;
	index = -1;
	while (tmp)
	{
		if (tmp->nbr < lowest)
		{
			lowest = tmp->nbr;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	ft_lowest_top_in_a(t_data *data)
{
	int	index;

	ft_data_cost_init(data);
	index = index_lower_nbr(data->stack_a);
	ft_cost_mediane(data->stack_a, index, data->cost_a);
	if (data->cost_a[1] == UP)
	{
		while (data->cost_a[0]--)
			ft_ra(data, 1);
	}
	if (data->cost_a[1] == DOWN)
	{
		while (data->cost_a[0]--)
			ft_rra(data, 1);
	}
}
