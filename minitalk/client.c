/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:47 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/07 17:23:13 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(__pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}
int	encode(__pid_t pid, char *str)
{
	int	i;
	i = 0;
	if (pid == -1)
	{
		ft_printf("ERREUR DE PID\n");
		return (-1);
	}
	while (str[i])
	{
		char_to_bin(pid, str[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		encode(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("Error : Put a PID and a sentence");
	}
}
