/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:57:44 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/09 16:13:29 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		t_size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	t_size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = malloc(t_size + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strdup(const char *source)
{
	int		i;
	char	*copied_s;

	i = 0;
	copied_s = malloc(ft_strlen(source) + 1);
	if (!copied_s)
		return (NULL);
	while (source[i])
	{
		copied_s[i] = source[i];
		i++;
	}
	copied_s[i] = '\0';
	return (copied_s);
}
