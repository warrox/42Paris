/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:14 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/21 15:00:40 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"
#include <stdio.h>

void	ft_pb(t_data *data)
{
	t_list	*first_a;

	if (!data->stack_a)
		return ;
	first_a = NULL;
	if (data && data->stack_a)
	{
		first_a = data->stack_a;
		data->stack_a = data->stack_a->next;
		first_a->next = NULL;
		ft_lstadd_front(&data->stack_b, first_a);
	}
	ft_printf("pb\n");
}

void	ft_pa(t_data *data)
{
	t_list	*first_b;

	if (!data->stack_b)
		return ;
	first_b = NULL;
	if (data && data->stack_b)
	{
		first_b = data->stack_b;
		data->stack_b = data->stack_b->next;
		first_b->next = NULL;
		ft_lstadd_front(&data->stack_a, first_b);
	}
	ft_printf("pa\n");
}

void	display_error(t_data *data)
{
	write(1, "Error\n", 6);
	ft_lstclear(&data->stack_a);
	if (data->argc == 2)
		split_destroy(data->argv);
	exit(1);
}

int	is_not_null(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (1);
	return (0);
}

int	is_lst_double_nb(t_list *lst)
{
	t_list	*temp;
	t_list	*current;
	int		check_nbr;

	current = lst;
	while (current->next)
	{
		temp = current;
		check_nbr = temp->nbr;
		while (temp->next)
		{
			if (check_nbr == temp->next->nbr)
				return (-1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
