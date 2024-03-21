/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:53 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/21 10:44:15 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

t_list	*ft_lstnew(long nb)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = nb;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast((*lst));
			tmp->next = new;
		}
	}
}

int	ft_list_lenght(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i + 1);
}
