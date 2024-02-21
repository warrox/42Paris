#include "psw_lib.h"

int main(int argc, char **argv)
{
	t_data data;
	data.argv = argv;
	data.i = -1;
	data.flag = 0;
	data.stack_a = NULL;
	data.stack_b = NULL;
	
	if(argc >= 1)
	{
		if(argc == 2 && is_not_null(argv[1]) == 0)
			data.argv = ft_split(argv[1], ' ');
		else
			data.argv = argv;
		while(data.argv[++data.i])
		{
			if (((ft_atoi_cust(data.argv[data.i]))== __LONG_MAX__ && data.flag == 1) || is_not_null(data.argv[data.i]) == 1)
			{
				display_error();
				return(-1);
			}
			if(ft_atoi_cust(data.argv[data.i])!= __LONG_MAX__)
				ft_lstadd_back(&data.stack_a,ft_lstnew(ft_atoi_cust(data.argv[data.i])));
			data.flag = 1;
		}
		data.i= 0;
		data.i = ft_list_lenght(data.stack_a);	
		if(is_lst_double_nb(data.stack_a) == - 1)
		{
			display_error();
			return(-1);
		}
		// create empty stack_b
		while(data.i != 0)
		{
			ft_lstadd_front(&data.stack_b,ft_lstnew(0));
			data.i--;
		}
		
		stack_visualizer(data.stack_a,data.stack_b);
	}
}


