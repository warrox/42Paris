/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:01 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/21 16:06:33 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int main(int argc, char **argv)
{
	t_data data;
	data.argv = argv;
	data.i = -1;
	data.flag = 0;
	data.argc = argc;
	data.stack_a = NULL;
	data.stack_b = NULL;
	
	if(data.argc >= 1)
	{
		if(data.argc == 2 && is_not_null(argv[1]) == 0)
				data.argv = ft_split(argv[1], ' ');
			else
				data.argv = argv;
		ft_psw_parser(&data);
	//	ft_push_a_to_b(&data);
		stack_visualizer(data.stack_a,data.stack_b);
	}
}


