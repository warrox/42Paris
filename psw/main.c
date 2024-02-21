#include "psw_lib.h"

int main(int argc, char **argv)
{
	t_data data;
	data.argv = argv;
	data.i = -1;
	data.flag = 0;
	data.argc = argc;
	data.stack_a = NULL;
	data.stack_b = NULL;
	
	if(data.argc >= 1)
	{
		if(data.argc == 2 && is_not_null(argv[1]) == 0)
				data.argv = ft_split(argv[1], ' ');
			else
				data.argv = argv;
		ft_psw_parser(&data);
		stack_visualizer(data.stack_a,data.stack_b);
	}
}


