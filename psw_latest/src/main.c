/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/21 10:42:21 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 1;
	data.argv = argv;
	data.i = 0;
	data.counter = 0;
	data.flag = 0;
	data.argc = argc;
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (data.argc >= 2)
	{
		if (data.argc == 2)
		{
			while (argv[i] != NULL)
				data.argv = ft_split(argv[i++], ' ');
		}
		ft_psw_parser(&data);
		ft_sort(&data);
		ft_lstclear(&data.stack_a);
		exit(1);
	}
}
