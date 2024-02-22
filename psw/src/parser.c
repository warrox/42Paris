/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:20 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/21 15:29:35 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int ft_psw_parser(t_data *data)
{
	while(data->argv[++data->i])
	{
		if (((ft_atoi_cust(data->argv[data->i]))== __LONG_MAX__ && data->flag == 1) || is_not_null(data->argv[data->i]) == 1)
		{
			display_error();
			return(-1);
		}
		if(ft_atoi_cust(data->argv[data->i])!= __LONG_MAX__)
			ft_lstadd_back(&data->stack_a,ft_lstnew(ft_atoi_cust(data->argv[data->i])));
		data->flag = 1;
	}
	data->i= 0;
	data->i = ft_list_lenght(data->stack_a);
	if(is_lst_double_nb(data->stack_a) == - 1)
	{
		display_error();
		exit(1);
	}
	// create empty stack_b
	while(data->i != 0)
	{
		ft_lstadd_front(&data->stack_b,ft_lstnew(0));
		data->i--;
	}
	return(0);
}
