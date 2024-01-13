/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:20 by whamdi            #+#    #+#             */
/*   Updated: 2024/01/13 14:58:34 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void decrypter(int signalValue)
{
	// recoit des signals SIGURSR1 & SIGUSR2 puis les displays en char
	static int power;
	static char byte;
	if(signalValue == SIGUSR2)
	{
		byte += 1 << (7 - power);
	}
	power++;
	if(power == 8)
	{
		write(1,&byte,1);
		power = 0;
		byte = 0;
	}
}

int main(void) 
{ 
	pid_t p_id;
	p_id = getpid();
	ft_printf("the pid is : %d",p_id); //diplay the pid
	ft_printf("\n");
	signal(SIGUSR1,decrypter);
	signal(SIGUSR2,decrypter);
	
	return(0);
}
 

