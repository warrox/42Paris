/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:20 by whamdi            #+#    #+#             */
/*   Updated: 2024/01/02 16:17:46 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdio.h>
#include "Printf/ft_printf.h"
#include <signal.h>
#include "minitalk.h"

int main(void) 
{ 
	int p_id;
	p_id = getpid();
	sigset_t set;
	sigemptyset(&set);	
	ft_printf("Process id : %d",p_id);
}
 

