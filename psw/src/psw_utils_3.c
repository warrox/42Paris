#include "psw_lib.h"

void ft_ra(t_data *data) // revoir cette logiaue
{
	s_list *save = data->stack_a;
	s_list *head = data->stack_a;
	s_list *new_head = data->stack_a->next;

	while (head->next)
		head = head->next;
	head->next = save;
	head->next->next = NULL;
	data->stack_a = new_head;

}

void ft_rb(t_data *data)
 {
		s_list *save	= data->stack_b;
		s_list *head = data->stack_b;
		s_list *new_head = data->stack_b->next;
		while (head->next)
			head = head->next;
		head->next = save;
		head->next->next = NULL;
		data->stack_b = new_head;
 }

void ft_rra(t_data *data)
 {
	s_list *save = data->stack_a;
	s_list *head;
	s_list *new_head = data->stack_a;
	while(new_head->next)
		new_head = new_head->next;
	new_head->next = save->next;
	head = new_head;
	while(head->next)
		head = head->next;
	head = NULL;
	new_head = head;
	data->stack_a = new_head;
}

void ft_rrb(t_data *data)
{
	s_list *save = data->stack_b;
	s_list *head;
	s_list *new_head = data->stack_b;
	while(new_head->next)
		new_head = new_head->next;
	new_head->next = save->next;
	head = new_head;
	while(head->next)
		head = head->next;
	head = NULL;
	new_head = head;
	data->stack_b = new_head;
}


