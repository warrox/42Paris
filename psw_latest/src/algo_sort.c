#include "psw_lib.h"
#include <stdio.h>


int higher_nbr(t_list *stack_b)
{
	int higher;
	higher = 0;
	t_list *temp = stack_b;
	while(temp->next)
	{
		if(higher < temp->nbr)
			higher = temp->nbr;
		temp = temp->next;
	}
	return(higher);
}
int lower_nbr(t_list *stack_b)
{
	int lower;
	lower = 0;
	t_list *temp = stack_b;
	while(temp->next)
	{
		if(lower < temp->nbr)
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

int ft_lowest_cost_sa(t_list *stack_a, t_list *stack_b,int i)
{
	// ici tu check toutes les conditions et tu renvoies le lowest cost
	t_list *tail_b;
	t_list *temp_a;
	t_list *temp_b;
	int index;

	temp_b = stack_b;
	temp_a = stack_a;
	tail_b = stack_b;

	while(tail_b->next)
		tail_b = tail_b->next;
	if(is_max_or_min(temp_a, temp_b)== 2 && temp_a->nbr > tail_b->nbr)
	{
		//rrb
		//pb
		return(2);
	}
	if(is_max_or_min(temp_a, temp_b)== 1 && temp_a->nbr < tail_b->nbr)
	{
		//rrr
		//pb
		return(2);
	}
	// calcul du cout rr en fonction de l'index dans a et b. 
	
}

//Check wich element in stack a are costless and return the index of this element
int	ft_cost(t_data *data)
{
	t_list *temp = data->stack_a;
	t_list *stack_b;
	int counter_cur;
	int counter_next;

	counter_cur = 0;
	counter_next = 0;
	stack_b = data->stack_b;
	data->i = 0;
	
	// ici faire une fonction qui renvoie le less cost de tous les next de b
	counter_cur = ft_lowest_cost_sa(temp,stack_b,data->i);
	temp = temp->next;
	while(temp->next)
	{
		counter_next = ft_lowest_cost_sa(temp,stack_b,data->i);
		if(counter_cur > counter_next && (counter_next - data->i) < counter_cur)
		{
			counter_cur = counter_next;
			data->i++;
		}
		temp = temp->next;
	}
	return(data->i);
}

void ft_doner(t_data *data)
{
	data->counter = 0;
	ft_pb(data);
	ft_pb(data);
	while(data->stack_a)
	{
		// count lowest cost for an element in stack_a
		data->counter = ft_cost(data); //element qui coute le moins a placer dans stack B
		if(is_max_or_min(data->stack_a, data->stack_b)== 1)
		{
			if(data->stack_a->nbr < data->stack_b->nbr) // si element < au top de stack b tu push + tu rb pour placer l'element en dernier.
			{
				ft_pb(data); 
				ft_rb(data);
			}
		}
		else if(is_max_or_min(data->stack_a, data->stack_b)== 2)
		{
			// higher
		}
		else
		{
			// is middle
		}
		data->stack_a = data->stack_a->next;
		// func to do 2
		// 2 :determinate if the current element to push is <min or >max or a middle numbers
	}
	//3 : puis calcul du cout pour chaque element
	//4 : Push
}




void ft_sort(t_data *data)
{
	// if 3, 4, >4
	if(ft_is_sorted(data) == 1)
		exit(EXIT_SUCCESS);
	/*while(ft_is_sorted(data) != 1)
	{
		HERE IS THE MAIN LOOP TRYING TO CHECK IF STACK IS SORTED
	}*/
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
