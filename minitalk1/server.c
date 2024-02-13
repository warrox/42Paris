/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:40 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/12 10:12:46 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_str(char *str)
{
	ft_printf("%s", str);
	free(str);
}

void	decoder(int signal, siginfo_t *client)
{
	static char	*str;
	static char	byte;
	static int	power;
	char		*temp;

	if (!str)
		str = ft_strdup("");
	if (signal == SIGUSR2)
		byte |= (1 << power);
	power++;
	if (power == 8)
	{
		temp = ft_strjoin(str, &byte);
		free(str);
		str = temp;
		if (byte == '\0')
		{
			kill(client->si_pid, SIGUSR2);
			display_str(str);
			str = NULL;
		}
		power = 0;
		byte = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = 0;
	pid = getpid();
	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = (void *)decoder;
	sigemptyset(&(sig.sa_mask));
	ft_printf("server connected, PID number : %d\n", pid);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
