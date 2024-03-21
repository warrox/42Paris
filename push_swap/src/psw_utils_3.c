/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:18 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 14:08:50 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	ft_ra(t_data *data, int flag)
{
	t_list	*save;
	t_list	*head;
	t_list	*new_head;

	if (!data->stack_a)
		return ;
	save = data->stack_a;
	head = data->stack_a;
	new_head = data->stack_a->next;
	while (head->next)
		head = head->next;
	head->next = save;
	head->next->next = NULL;
	data->stack_a = new_head;
	if (flag == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_data *data, int flag)
{
	t_list	*save;
	t_list	*head;
	t_list	*new_head;

	if (!data->stack_b)
		return ;
	save = data->stack_b;
	head = data->stack_b;
	new_head = data->stack_b->next;
	while (head->next)
		head = head->next;
	head->next = save;
	head->next->next = NULL;
	data->stack_b = new_head;
	if (flag == 1)
		ft_printf("rb\n");
}

void	ft_rra(t_data *data, int flag)
{
	t_list	*save;
	t_list	*last;
	t_list	*last_prev;

	if (!data->stack_a)
		return ;
	save = data->stack_a;
	last_prev = data->stack_a;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last = last_prev->next;
	last_prev->next = NULL;
	last->next = save;
	data->stack_a = last;
	if (flag == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_data *data, int flag)
{
	t_list	*save;
	t_list	*last;
	t_list	*last_prev;

	if (!data->stack_b)
		return ;
	save = data->stack_b;
	last_prev = data->stack_b;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last = last_prev->next;
	last_prev->next = NULL;
	last->next = save;
	data->stack_b = last;
	if (flag == 1)
		ft_printf("rrb\n");
}

void	ft_sa(t_data *data, int flag)
{
	t_list	*head;
	t_list	*temp;

	if (!data->stack_a)
		return ;
	head = data->stack_a;
	temp = data->stack_a->next;
	data->stack_a->next = temp->next;
	data->stack_a = temp;
	data->stack_a->next = head;
	if (flag == 1)
		ft_printf("sa\n");
}
