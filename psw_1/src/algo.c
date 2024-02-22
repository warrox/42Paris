#include "psw_lib.h"
void ft_swap_2(s_list **stack_a)
{
	s_list *first;
	s_list *second;
	first = *stack_a;
	second = first->next;

	
	second->next = first;
	second->next = first->next;

	*stack_a = second;
}