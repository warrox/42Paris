/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:53 by whamdi            #+#    #+#             */
/*   Updated: 2024/02/22 15:32:47 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "psw_lib.h"

s_list	*ft_lstnew(long nb)
{
	s_list	*new;
	new = (s_list *)malloc(sizeof(s_list));
	if (!new)
		return (NULL);
	new->nbr = nb;
	new->next = NULL;
	return (new);
}
void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
s_list	*ft_lstlast(s_list *lst)
{
	s_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
void	ft_lstadd_back(s_list **lst, s_list *new)
{
	s_list	*tmp;

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
int ft_list_lenght(s_list *lst)
{
	int i;
	s_list *temp;
	temp = lst;
	i = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return(i + 1);// not sure to check if valid
}






