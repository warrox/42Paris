/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:47 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/12 08:58:15 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_sign_received = 0;

void	char_to_bin(__pid_t pid, char c)
{
	int	i;
	int	timer;

	i = 0;
	while (i < 8)
	{
		timer = 0;
		g_sign_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		while (!g_sign_received && timer < 500)
		{
			usleep(5000);
			timer++;
		}
		if (timer == 500)
		{
			ft_printf("<Aucune reponse du serveur> .. Fermeture du client");
			exit(EXIT_FAILURE);
		}
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
	if (str[0] == '\0')
	{
		ft_printf("Empty string, try again with characters\n");
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		char_to_bin(pid, str[i]);
		i++;
	}
	char_to_bin(pid, 0);
	return (0);
}

void	handler(int signal, siginfo_t *client, void *ucontext)
{
	int		i;
	char	*str;

	(void)ucontext;
	(void)client;
	if (signal == SIGUSR1)
		g_sign_received = 1;
	else if (signal == SIGUSR2)
	{
		i = 0;
		str = "Message succesfully sent to the server";
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc == 3)
	{
		sig.sa_flags = SA_SIGINFO;
		sig.sa_handler = (void *)handler;
		sigemptyset(&(sig.sa_mask));
		sigaction(SIGUSR2, &sig, NULL);
		sigaction(SIGUSR1, &sig, NULL);
		encode(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("Error : Put a PID and a sentence");
		exit(EXIT_FAILURE);
	}
}
