/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:00:00 by whamdi            #+#    #+#             */
/*   Updated: 2024/01/13 15:41:46 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	encoder(pid_t pid, char *str)
{
	int i = 0;
	int bit = 0;
	if(pid > 1)
	{
		while(str[i])
		{
			bit = 1 << str[i]; // NOT SURE but conversion into binary
			kill(pid,bit); //send the binary content to server
			i++;
		}
	}
	else
	{
		return(-1);
	}
}

int main(int argc, char **argv)
{
	if(argc == 3) // pid + string
	{
		encoder //argv[1] = PID + argv[2] = STR
	}
}