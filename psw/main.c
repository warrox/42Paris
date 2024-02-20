#include "psw_lib.h"

int main(int argc, char **argv)
{
	int i;
	i = -1;
	int flag = 0; // Pourquoi quand je passe i = 0 ca ne m'affiche pas le premier int du stack_a
	s_list *stack_a;
	s_list *stack_b;
	stack_a = NULL;
	stack_b = NULL;
	if(argc > 1)
	{
		while(argv[++i])
		{
			if ((ft_atoi_cust(argv[i]))== __LONG_MAX__ && flag == 1)
			{
				write(1,"Error\n",6);
				return(-1);
			}
			ft_lstadd_front(&stack_a,ft_lstnew(ft_atoi_cust(argv[i])));
			flag = 1;
		}
	
		i = 0;
		i = ft_list_lenght(stack_a);
		// TODO check if unique nbr in the list
		if(is_lst_clean(stack_a,i) == - 1)
		{
			display_error();
			return(-1);
		}
		// create empty stack_b
		while(i != 0)
		{
			ft_lstadd_front(&stack_b,ft_lstnew(0));
			i--;
		}
		stack_visualizer(stack_a,stack_b);
		// while(stack_a->next != NULL) // testing
		// {
		// 	printf("%ld\n",stack_a->nbr);
		// 	stack_a = stack_a->next;
		// }
	}
}


