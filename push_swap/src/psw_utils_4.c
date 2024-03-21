/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:26:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 14:22:52 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_sb(t_data *data, int flag)
{
	t_list	*head;
	t_list	*temp;

	if (!data->stack_b)
		return ;
	head = data->stack_b;
	temp = data->stack_b->next;
	data->stack_b->next = temp->next;
	data->stack_b = temp;
	data->stack_b->next = head;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ft_ss(t_data *data)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	ft_printf("ss\n");
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
	ft_printf("rr\n");
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
	ft_printf("rrr\n");
}
