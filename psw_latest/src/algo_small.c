/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:23 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/15 16:34:40 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void ft_sort_3(t_data *data)
{
	int el1;
	int el2;
	int el3;
	el1 = data->stack_a->nbr;
	el2 = data->stack_a->next->nbr;
	el3 = data->stack_a->next->next->nbr;

	if(lower_nbr(data->stack_a) == el1)
	{
		ft_rra(data);
		ft_sa(data);
	}
	else if (higher_nbr(data->stack_a) == el1)
	{
		ft_ra(data);
		if(!ft_is_sorted(data))
			ft_sa(data);
	}
	if(lower_nbr(data->stack_a) == el3)
		ft_rra(data);
	if(!ft_is_sorted(data))
		ft_sort_3(data);
	
}
void	ft_sort_2(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
}