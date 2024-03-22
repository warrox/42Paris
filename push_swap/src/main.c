/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/22 14:12:47 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

void	split_destroy(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

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
			data.argv = ft_split(argv[1], ' ');
		ft_psw_parser(&data);
		ft_sort(&data);
		ft_lstclear(&data.stack_a);
		if (argc == 2)
			split_destroy(data.argv);
		exit(1);
	}
}
