#include "psw_lib.h"
#include <stdio.h>

int ft_is_sorted(t_data *data)
{
	s_list *temp;
	s_list *current;
	current = data->stack_a;
	temp = data->stack_a->next;
	while(current && temp)
	{
		if(current->nbr > temp->nbr)
			return(0);
		temp = temp->next;
		current = current->next;
	}
	return(1);
}
void ft_sort_3(t_data *data)
{
	
	while(ft_is_sorted(data) != 1)
	{
		if(data->stack_a->nbr > data->stack_a->next->nbr && 
		data->stack_a->nbr > data->stack_a->next->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		else if (data->stack_a->nbr < data->stack_a->next->nbr && 
		data->stack_a->nbr > data->stack_a->next->next->nbr)
		{
			ft_rra(data);
			data->counter++;
		}

		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_sa(data);
			data->counter++;
		}
		if(data->stack_a->next->nbr > data->stack_a->next->next->nbr)
		{
			ft_rra(data);
			data->counter++;
		}
	}
	
}
void	ft_sort_2(t_data *data)
{
	if(data->stack_a->nbr > data->stack_a->next->nbr)
	{
		ft_sa(data);
		data->counter++;
	}
}
void	ft_sort_4(t_data *data) // do not work with 1 4 3 2 // maj : ca va pas te servir
{
	// mi
	
	while(ft_is_sorted(data)!= 1) // not working
	{
		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		else if(data->stack_a->nbr < data->stack_a->next->nbr &&
		data->stack_a->nbr < data->stack_a->next->next->nbr)
		{
			ft_ra(data);
			data->counter++;
		}
		if(data->stack_a->nbr > data->stack_a->next->nbr)
		{
			ft_sa(data);
			data->counter++;
		}
		if(data->counter == 4)
		{
			ft_ra(data);
			data->counter++;
		}
		printf("DATA COUNTER : %d\n",data->counter);
	}
}
int higher_nbr(s_list *stack_b)
{
	int higher;
	higher = 0;
	s_list *temp = stack_b;
	while(temp->next)
	{
		if(higher < temp->nbr)
			higher = temp->nbr;
		temp = temp->next;
	}
	return(higher);
}
int lower_nbr(s_list *stack_b)
{
	int lower;
	lower = 0;
	s_list *temp = stack_b;
	while(temp->next)
	{
		if(lower < temp->nbr)
			lower = temp->nbr;
		temp = temp->next;
	}
	return(lower);
}
int is_max_or_min(s_list *stack_a, s_list *stack_b)
{
	
	if(stack_a->nbr < lower_nbr(stack_b))
		return(1);
	if(stack_a->nbr > higher_nbr(stack_b))
		return(2);

	return(0);
}
//Check wich element in stack a are costless and return the index of this element
int	ft_cost(t_data *data)
{
	s_list *temp = data->stack_a;
	int counter_cur;
	int counter_next;

	int index_next;
	s_list *stack_b;
	index_next = 0;
	counter_cur = 0;
	counter_next = 0;
	stack_b = data->stack_b;
	data->i = 0;
	while(stack_b->next)
		stack_b = stack_b->next;

	if(temp->nbr < data->stack_b->nbr && temp->nbr < stack_b->nbr)
	{
		counter_cur++;
		temp = temp->next;
	}

	// foret de if avec toutes les conditions
	while(temp->next)
	{
		if(temp->nbr < data->stack_b->nbr && temp->nbr < stack_b->nbr)
		{
			counter_next++;
			temp = temp->next;
		}
		// foret de if avec toutes les conditions
		if(counter_cur < counter_next)
			return(data->i);
		else
		{
			counter_cur = counter_next;
			counter_next = 0;
		}
		counter_next++;
	}
	return(counter_next);
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
