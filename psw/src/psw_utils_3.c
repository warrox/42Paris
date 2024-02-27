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

	stack_visualizer(data->stack_a, data->stack_b);
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

		stack_visualizer(data->stack_a,data->stack_b);
 }

// void ft_rra(t_data *data)
// {
// 	s_list *temp;
// 	data->stack_a
// }

// void ft_rrb(t_data *data)
// {

// }


