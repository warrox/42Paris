/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:01:56 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/19 18:03:34 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
void ft_data_cost_init(t_data *data)
{
	data->final_cost = INT_MAX;
	data->f_cost_a[0] = INT_MAX;
	data->f_cost_a[1] = INT_MAX;
	data->f_cost_b[0] = INT_MAX;
	data->f_cost_b[1] = INT_MAX;
	data->i = 0;
}
int push_lowest_top(t_list *a)
{
	t_list *tmp = a;
	int lowest = INT_MAX;
	int i = 0;
	int index = -1;
	
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