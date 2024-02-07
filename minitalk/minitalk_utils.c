/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:44 by whamdi            #+#    #+#             */
/*   Updated: 2024/01/19 10:24:01 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!(str[i] >= '0') && !(str[i] <= '9'))
		{
			return (-1);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
