/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:27 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/07 14:33:23 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	decoder(int signal);
void	ft_putchar(char c);
int		encode(__pid_t pid, char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
