/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/20 15:30:59 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.argv = argv;
	data.i = 0;
	data.counter = 0;
	data.flag = 0;
	data.argc = argc;
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (data.argc >= 2)
	{
		if (data.argc == 2 && is_not_null(argv[1]) == 0
			&& ft_atoi_cust(argv[1]) != LONG_MAX)
			data.argv = ft_split(argv[1], ' ');
		if (ft_atoi_cust(argv[1]) == LONG_MAX)
			display_error();
		else
			data.argv = argv;
		ft_psw_parser(&data);
		ft_sort(&data);
		ft_lstclear(&data.stack_a);
		exit(1);
	}
}
