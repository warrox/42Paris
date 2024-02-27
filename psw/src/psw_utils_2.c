#include "psw_lib.h"
#include <stdio.h>

void ft_push_a_to_b(t_data *data)
{
    s_list *temp;
		data->i = ft_list_lenght(data->stack_a);    
		while (data->i > 3) // modifier par rappoort au turc algo
    {
        temp = data->stack_a;
        data->stack_a = data->stack_a->next;

        temp->next = data->stack_b;
        data->stack_b = temp;
		data->i--;
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

void stack_visualizer(s_list *stack_a,s_list *stack_b)
{
	s_list **head_a = &stack_a;
	s_list **head_b = &stack_b;
	
	if(head_a == NULL)
	 	return;
	
	printf("Stack A\t\n");
	while((*head_a))
	{
		printf("  |%ld|\t",(*head_a)->nbr);
		printf("\n");
		(*head_a) = (*head_a)->next;
	}
	 if(head_b == NULL)
	 	return;
	printf("Stack B\t\n");
	 while((*head_b))
	 {
	 	printf("  |%ld|\t",(*head_b)->nbr);
	 	printf("\n");
	  	(*head_b) = (*head_b)->next;
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
