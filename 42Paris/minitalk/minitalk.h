/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:27 by whamdi            #+#    #+#             */
/*   Updated: 2024/01/13 12:02:14 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include <unistd.h> 
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
typedef struct s_sign
{
	int sign;
	struct s_sign *next;

} t_sign;

