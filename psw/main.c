#include "psw_lib.h"

int main(int argc, char **argv)
{
	char **str;
	int i;
	i = -1;
	int flag = 0; // Pourquoi quand je passe i = 0 ca ne m'affiche pas le premier int du stack_a
	s_list *stack_a;
	s_list *stack_b;
	stack_a = NULL;
	stack_b = NULL;
	if(argc >= 1)
	{
		if(argc == 2 && is_not_null(argv[1]) == 0)
			str = ft_split(argv[1], ' ');
		else
			str = argv;
		while(str[++i])
		{
			if (((ft_atoi_cust(str[i]))== __LONG_MAX__ && flag == 1) || is_not_null(str[i]) == 1)
			{
				display_error();
				return(-1);
			}
			ft_lstadd_front(&stack_a,ft_lstnew(ft_atoi_cust(str[i])));
			flag = 1;
		}
	
		i = 0;
		i = ft_list_lenght(stack_a);
		if(is_lst_double_nb(stack_a) == - 1)
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
	}
}


