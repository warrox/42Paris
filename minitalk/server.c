/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:40 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/07 17:33:52 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	decoder(int signal)
{
	static int	power;
	static char	byte;
	if (signal == SIGUSR2)
	{
		byte	|= (1 << power);
	}
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}
int	main(void)
{
	pid_t	pid;
	pid = 0;
	pid = getpid();
	ft_printf("server connected, PID number : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, decoder);
		signal(SIGUSR2, decoder);
		pause();
	}
	return (0);
}
