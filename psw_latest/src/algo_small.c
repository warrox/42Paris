/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:23 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 14:10:19 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_sort_3(t_data *data)
{
	int	el1;
	int	el2;
	int	el3;

	el1 = data->stack_a->nbr;
	el2 = data->stack_a->next->nbr;
	el3 = data->stack_a->next->next->nbr;
	if (higher_nbr(data->stack_a) == el1)
		ft_ra(data, 1);
	if (higher_nbr(data->stack_a) == el2)
	{
		ft_rra(data, 1);
	}
	if (data->stack_a->nbr > data->stack_a->next->nbr)
		ft_sa(data, 1);
}

void	ft_sort_2(t_data *data)
{
	if (data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data, 1);
		data->counter++;
	}
}
