/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:27:25 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/14 11:29:04 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw_lib.h"

int lower_nbr(t_list *stack_b)
{
	int lower;
	lower = INT_MAX;
	t_list *temp = stack_b;
	while(temp)
	{
		if(temp->nbr < lower)
			lower = temp->nbr;
		temp = temp->next;
	}
	return(lower);
}
int is_max_or_min(t_list *stack_a, t_list *stack_b)
{
	
	if(stack_a->nbr < lower_nbr(stack_b))
		return(1);
	if(stack_a->nbr > higher_nbr(stack_b))
		return(2);
	return(0);
}

int index_middle_nbr(t_data *data)
{
    int nbr;
    int index;
    int f_index = -1;
    int dif;
    int best_dif = INT_MAX;
    t_list *stack_b = data->stack_b;
    nbr = data->stack_a->nbr;

    index = 0;
    while (stack_b != NULL)
    {
        if (stack_b->nbr < nbr)
        {
            dif = nbr - stack_b->nbr;
            if (dif < best_dif)
            {
                best_dif = dif;
                f_index = index;
            }
        }
        stack_b = stack_b->next;
        index++;
    }
    return (f_index);
}


int index_lower_nbr(t_list *stack_b)
{
	long lower;
	int index;
	int r_index;
	lower = INT_MAX;
	index = 0;
	r_index = INT_MAX;
	t_list *temp = stack_b;
	while(temp != NULL)
	{
		if(temp->nbr < lower)
		{
			lower = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return(r_index);
}

int index_higher_nbr(t_list *stack_b)
{
	long higher;
	int index;
	int r_index;
	higher = INT_MIN;
	index = 0;
	r_index = INT_MAX;
	t_list *temp = stack_b;
	while(temp)
	{
		if(temp->nbr > higher)
		{
			higher = temp->nbr;
			r_index = index;
		}
		temp = temp->next;
		index++;
	}
	return(r_index);
}