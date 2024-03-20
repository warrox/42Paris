/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:25:36 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 10:16:50 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int	ft_is_sorted(t_data *data)
{
	t_list	*temp;
	t_list	*current;

	current = data->stack_a;
	temp = data->stack_a->next;
	while (current && temp)
	{
		if (current->nbr > temp->nbr)
			return (0);
		temp = temp->next;
		current = current->next;
	}
	return (1);
}
