void	stack_a_visualizer(t_list *stack_a)
{
	t_list	*copy;

	copy = stack_a;
	if (!copy)
		return ;
	ft_printf("Stack A\n");
	while (copy)
	{
		printf("|%ld|\n", copy->nbr);
		copy = copy->next;
	}
}

void	stack_b_visualizer(t_list *stack_b)
{
	t_list	*copy;

	copy = stack_b;
	if (!copy)
		return ;
	ft_printf("Stack B\n");
	while (copy)
	{
		printf("|%ld|\n", copy->nbr);
		copy = copy->next;
	}
}