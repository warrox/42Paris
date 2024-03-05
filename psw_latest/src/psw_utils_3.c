#include "psw_lib.h"
#include <stdio.h>

void ft_ra(t_data *data) // revoir cette logiaue
{
	if(!data->stack_a)
		return;
	t_list *save = data->stack_a;
	t_list *head = data->stack_a;
	t_list *new_head = data->stack_a->next;

	while (head->next)
		head = head->next;
	head->next = save;
	head->next->next = NULL;
	data->stack_a = new_head;

}

void ft_rb(t_data *data)
 {
	if(!data->stack_b)
		return;
	t_list *save = data->stack_b;
	t_list *head = data->stack_b;
	t_list *new_head = data->stack_b->next;
	while (head->next)
		head = head->next;
	head->next = save;
	head->next->next = NULL;
	data->stack_b = new_head;
 }

void ft_rra(t_data *data)
 {
	if(!data->stack_a)
		return;
	t_list *save = data->stack_a;
	t_list *last;
	t_list *last_prev = data->stack_a;
	while(last_prev->next->next)
		last_prev = last_prev->next;
	last = last_prev->next;
	last_prev->next = NULL;
	last->next = save;
	data->stack_a = last;
}

void ft_rrb(t_data *data)
{
	if(!data->stack_b)
		return;
	t_list *save = data->stack_b;
	t_list *last;
	t_list *last_prev = data->stack_b;
	while(last_prev->next->next)
		last_prev = last_prev->next;
	last = last_prev->next;
	last_prev->next = NULL;
	last->next = save;
	data->stack_b = last;
}
void ft_sa(t_data *data)
{
	if(!data->stack_a)
		return;
	t_list *head = data->stack_a;
	t_list *temp = data->stack_a->next;
	
	data->stack_a->next = temp->next;
	data->stack_a = temp;
	data->stack_a->next = head;
}
void ft_sb(t_data *data)
{
	if(!data->stack_b)
		return;
	t_list *head = data->stack_b;
	t_list *temp = data->stack_b->next;
	
	data->stack_b->next = temp->next;
	data->stack_b = temp;
	data->stack_b->next = head;
}
void ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
}
void ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
}

void ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
}

void counter_print(t_data *data)
{
	printf("\nNumber of operation(s) : O(%d)\n",data->counter);
}


