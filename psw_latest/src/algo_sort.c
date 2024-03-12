#include "psw_lib.h"
#include <stdio.h>
#include <stdlib.h>

void ft_cost_mediane(t_list *stack, int i, int *cost) // not working
{
	int med;


	med = ft_list_lenght(stack) / 2;
	if (i > med)
	{
		// ft_printf("--------\n");
		// ft_printf("%d*valeur de i : %d\n",stack->nbr, i);
		// ft_printf("valeur de med : %d\n", med);
		cost[0] = med - (i - med);
		cost[1] = DOWN;
	}
	else
	{
		// ft_printf("%d*valeur de i : %d\n",stack->nbr, i);
		// ft_printf("valeur de med : %d\n", med);
		// ft_printf("--------\n");
		cost[0] = i;
		cost[1] = UP;
	}
}

int higher_nbr(t_list *stack_b)
{
	int higher;
	higher = INT_MIN;
	t_list *temp = stack_b;
	while(temp)
	{
		if(temp->nbr > higher)
			higher = temp->nbr;
		temp = temp->next;
	}
	return(higher);
}
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
	{
		return(1);
	}
	// printf("stack_a->nbr = %ld, highest = %d\n", stack_a->nbr, higher_nbr(stack_b));
	if(stack_a->nbr > higher_nbr(stack_b))
	{
		return(2);
	}
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
int ft_simplify_cost(t_data *data)
{
	int cost;
	cost = data->cost_a[0] + data->cost_b[0];
	
	if(data->cost_a[1] == data->cost_b[1] && data->cost_a[0] > 0)
	{
		cost -=1;
	}
	return(cost);
}
int ft_lowest_cost_sa(t_data *data,t_list *stack)
{
	int cost;
	data->cost_a[0] = 0;
	data->cost_a[1] = 0;
	data->cost_b[0]= 0;
	data->cost_b[1]= 0;
	data->index_b = 0;
	cost = 0;
	(void) stack;
	if(is_max_or_min(stack,data->stack_b) == 2 || is_max_or_min(stack,data->stack_b) == 1)
	{
		ft_cost_mediane(data->stack_a, data->i, data->cost_a);
		data->index_b = index_higher_nbr(data->stack_b);
		ft_cost_mediane(data->stack_b, data->index_b, data->cost_b);
	}
	else if(is_max_or_min(stack,data->stack_b) == 0)
	{
		ft_cost_mediane(data->stack_a, data->i, data->cost_a);
		data->index_b = index_middle_nbr(data);
		ft_cost_mediane(data->stack_b, data->index_b, data->cost_b);
	}
	cost =  ft_simplify_cost(data);
	return(cost);
}

//Check wich element in stack a are costless and return the index of this element
int	ft_cost(t_data *data)
{
	t_list *temp_a = data->stack_a;
	int counter_cur = 0;
	int cur_lowest = INT_MAX;
	data->final_cost = INT_MAX;
	data->f_cost_a[0] = INT_MAX;
	data->f_cost_a[1] = INT_MAX;
	data->f_cost_b[0] = INT_MAX;
	data->f_cost_b[1] = INT_MAX;
	data->i = 0;
	while(temp_a != NULL)
	{
		counter_cur = ft_lowest_cost_sa(data,temp_a);
		ft_printf("counter_cur : %d\n", counter_cur);
		ft_printf("Final_cost : %d\n", data->final_cost);
		if(data->final_cost == 0)
			return(0);
		if (counter_cur < data->final_cost)
		{
			data->final_cost = counter_cur;
			data->f_cost_a[0] = data->cost_a[0];
			data->f_cost_a[1] = data->cost_a[1];
			data->f_cost_b[0] = data->cost_b[0];
			data->f_cost_b[1] = data->cost_b[1];
			//ft_printf("Finalcost for element : %d\n",data->final_cost);
			cur_lowest = data->i;
		}
		data->i++;
		temp_a = temp_a->next;
	}
	
	  if(data->stack_a->nbr == 8)
	 	exit(1);	
	return(cur_lowest);
}
void ft_action(t_data *data) // recupere mes instructions de a et b 
{
	ft_cost(data);
	if(data->final_cost == 0)
	{
		ft_pb(data);
		return;
	}
	if(data->final_cost == 1)
	{
		if(data->cost_b[1] == 1)
		{
			while(data->cost_b[0])
			{
				ft_rb(data);
				data->cost_b[0]--;
			}
		}
		return;
	}
	// TO CHECK
	if(data->cost_a[1] == 1)
	{
		while(data->cost_a[0])
		{
			ft_printf("cost_a[0] : %d\n",data->cost_a[0]);
			ft_ra(data);
			data->cost_a[0]--;
		}
	}
	else if(data->cost_a[1] == 1 && data->cost_a[1] == data->cost_b[1])
	{
		while(data->cost_a[0])
		{
			ft_printf("cost_a[0] : %d\n",data->cost_a[0]);
			ft_rr(data);
			data->cost_a[0]--;
		}
	}
			
	if(data->cost_a[1] == 2)
	{
		while(data->cost_a[0])
		{
			ft_printf("cost_a[0] : %d\n",data->cost_a[0]);
			ft_rra(data);
			data->cost_a[0]--;
		}
	}
	else if(data->cost_a[1] == 2 && data->cost_a[1] == data->cost_b[1])
	{
		while(data->cost_a[0])
		{
			ft_printf("cost_a[0] : %d\n",data->cost_a[0]);
			ft_rrr(data);
			data->cost_a[0]--;
		}
	}
		data->final_cost--;
		
}
void ft_doner(t_data *data)
{
	ft_pb(data);
	ft_pb(data);
	while(ft_list_lenght(data->stack_a) > 3)
	{
		ft_action(data);
		//ft_pb(data);
		stack_b_visualizer(data->stack_b);
	}
	if(ft_list_lenght(data->stack_a)== 3)
		ft_sort_3(data);
}




void ft_sort(t_data *data)
{
	// if 3, 4, >4
	// if sorted
	if(ft_list_lenght(data->stack_a) == 2)
		ft_sort_2(data);
	if(ft_list_lenght(data->stack_a) == 3)
		ft_sort_3(data);
	if(ft_list_lenght(data->stack_a) > 4)
		ft_doner(data);
	// if(ft_list_lenght(data->stack_a) == 4)
	// 	ft_sort_4(data);
	// if(ft_list_lenght(data->stack_a) > 4)
	// 	ft_pa(data);
}
