/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:10 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/14 11:26:11 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && first[i] != '\0' && second[i] != '\0')
	{
		if ((unsigned char)first[i] > (unsigned char)second[i])
			return (1);
		else if ((unsigned char)first[i] < (unsigned char)second[i])
			return (-1);
		i++;
	}
	if (i == length || (first[i] == '\0' && second[i] == '\0'))
		return (0);
	else if (first[i] == '\0')
		return (-1);
	else
		return (1);
}

long ft_atoi_cust(const char *nbr)
{
	int	result;
	int	sign;
	const char *save;

	sign = 1;
	result = 0;
	save = nbr;
	if (*nbr && (*nbr == '-'))
	{
			sign *= -1;
			nbr++;
	}
	if(*nbr == '+')
		return(__LONG_MAX__);
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + result * 10;
	if(!ft_strncmp(ft_itoa(result*sign),save,ft_strlen(save)))
		return((long)result * sign);
	return(__LONG_MAX__);
}