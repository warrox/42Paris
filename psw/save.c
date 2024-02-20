#include "psw_lib.h"

int main(int argc, char **argv)
{
	int i;
	i = -1;
	s_list *head;
	s_list *stack_b;
	head = NULL;
	stack_b = NULL;
	if(argc > 1)
	{
		while(argv[++i])
			ft_lstadd_front(&head,ft_lstnew(ft_atoi_cust(argv[i])));
		i = 0;
		i = ft_list_lenght(head);
		// create empty stack_b
		while(i != 0)
		{
			ft_lstadd_front(&stack_b,ft_lstnew(0));
			i--;
		}
		stack_visualizer(head,stack_b);
		// while(head->next != NULL) // testing
		// {
		// 	printf("%ld\n",head->nbr);
		// 	head = head->next;
		// }
	}
}


