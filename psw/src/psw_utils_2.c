#include "psw_lib.h"

void ft_push_a_to_b(t_data *data) // TO DEBUG You don't modify the list like this.
{
	t_data *temp;
	temp = data;
	temp->i = ft_list_lenght(temp->stack_a);
	while(temp->i > 3)
	{
		temp->stack_a = data->stack_a;
		temp->stack_b = data->stack_b;
		
		temp->i--;
	}
	
}

void display_error(void)
{
	write(1,"Error\n",6);
}

int is_not_null(char *str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	if(i == 0)
		return(1);
	return(0);
}

void stack_visualizer(s_list *stack_a, s_list *stack_b)
{
	int flag = 0;
	while(stack_a && stack_b)
	{
		if(flag == 0)
			printf("Stack A\t Stack B\n");
		flag = 1;
		printf("  |%ld|\t",stack_a->nbr);
		printf("  |%ld|\t",stack_b->nbr);
		printf("\n");
		stack_a = stack_a -> next;
		stack_b = stack_b -> next;
	}
}
int		is_lst_double_nb(s_list *lst)
{
	s_list *temp;
	s_list *current;
	current = lst;
	int check_nbr;
	while(current->next)
	{
		temp = current;
		check_nbr = temp->nbr;
		while(temp->next)
		{
			if(check_nbr == temp->next->nbr)
				return(-1);
			temp = temp->next;
		}	
		current = current->next;
	}	
	return(0);
}
