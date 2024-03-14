#include "psw_lib.h"
#include <stdio.h>
#include <stdlib.h>

void ft_cost_mediane(t_list *stack, int i, int *cost) // not working
{
	int med;
	int len;

	len = ft_list_lenght(stack);
	med = len / 2;
	if (i > med)
	{
		cost[0] = len - i; 
		cost[1] = DOWN;
	}
	else
	{
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
int ft_simplify_cost(t_data *data)
{
	int cost;
	int tmp_costa;
	int tmp_costb;

	cost = data->cost_a[0] + data->cost_b[0];
	tmp_costa = data->cost_a[0];
	tmp_costb = data->cost_b[0];
	while(data->cost_a[1] == data->cost_b[1] && (tmp_costa > 0 && tmp_costb > 0))
	{
		cost -=1;
		tmp_costa -=1;
		tmp_costb -=1;
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
		ft_printf("Index b : %d\n",data->index_b);
		ft_cost_mediane(data->stack_b, data->index_b, data->cost_b);
		ft_printf("--------\n");
	}
	cost =  ft_simplify_cost(data);
	return(cost);
}
void ft_data_cost_init(t_data *data)
{
	data->final_cost = INT_MAX;
	data->f_cost_a[0] = INT_MAX;
	data->f_cost_a[1] = INT_MAX;
	data->f_cost_b[0] = INT_MAX;
	data->f_cost_b[1] = INT_MAX;
	data->i = 0;
}
//Check wich element in stack a are costless and return the index of this element
int	ft_cost(t_data *data)
{
	t_list *temp_a = data->stack_a;
	int counter_cur = 0;
	int cur_lowest = INT_MAX;
	ft_data_cost_init(data);
	while(temp_a != NULL)
	{
		counter_cur = ft_lowest_cost_sa(data,temp_a);
		if(data->final_cost == 0)
			return(0);
		if (counter_cur < data->final_cost)
		{
			data->final_cost = counter_cur;
			data->f_cost_a[0] = data->cost_a[0];
			data->f_cost_a[1] = data->cost_a[1];
			data->f_cost_b[0] = data->cost_b[0];
			data->f_cost_b[1] = data->cost_b[1];
			cur_lowest = data->i;
		}
		data->i++;
		temp_a = temp_a->next;
	}
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
	if(data->f_cost_a[1] == UP && data->f_cost_b[1] == UP)
	{
		while(data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if(data->f_cost_a[1] == UP)
	{
		while(data->f_cost_a[0] > 0)
		{
			ft_ra(data);
			data->f_cost_a[0]--;
		}
	}
	if(data->f_cost_b[1] == UP)
	{
		while(data->f_cost_b[0] > 0)
		{
			ft_rb(data);
			data->f_cost_b[0]--;
		}
	}
	
	if(data->f_cost_a[1] == DOWN && data->f_cost_b[1] == DOWN)
	{
		while(data->f_cost_a[0] > 0 && data->f_cost_b[0] > 0)
		{
			ft_rrr(data);
			data->f_cost_a[0]--;
			data->f_cost_b[0]--;
		}
	}
	if(data->f_cost_a[1] == DOWN)
	{
		while(data->f_cost_a[0] > 0)
		{
			ft_rra(data);
			data->f_cost_a[0]--;
		}
	}
	if(data->f_cost_b[1] == DOWN)
	{
		while(data->f_cost_b[0] > 0)
		{
			ft_rrb(data);
			data->f_cost_b[0]--;
		}
	}
	ft_pb(data);
}

void ft_doner(t_data *data)
{
	ft_pb(data);
	ft_pb(data);
	while(ft_list_lenght(data->stack_a) > 3)
	{
		ft_action(data);
		stack_a_visualizer(data->stack_a);
		stack_b_visualizer(data->stack_b);
		// if(data->stack_b->nbr == 3)
	 	// 	exit(1);
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
