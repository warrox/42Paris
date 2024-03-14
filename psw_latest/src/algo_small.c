/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:23 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/14 15:03:29 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
void ft_sort_3(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr && 
	data->stack_a->nbr > data->stack_a->next->next->nbr)
	{
		ft_ra(data);
		data->counter++;
	}
	else if (data->stack_a->nbr < data->stack_a->next->nbr && 
	data->stack_a->nbr > data->stack_a->next->next->nbr)
	{
		ft_rra(data);
		data->counter++;
	}

	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
	if(data->stack_a->next->nbr > data->stack_a->next->next->nbr)
	{
		ft_rra(data);
		data->counter++;
	}
	if(data->stack_a->next->next->nbr > data->stack_a->nbr)
		ft_rra(data);
}
void	ft_sort_2(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
}