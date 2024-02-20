#include "psw_lib.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && first[i] != '\0' && second[i] != '\0')
	{
		if ((unsigned char)first[i] > (unsigned char)second[i])
			return (1);
		else if ((unsigned char)first[i] < (unsigned char)second[i])
			return (-1);
		i++;
	}
	if (i == length || (first[i] == '\0' && second[i] == '\0'))
		return (0);
	else if (first[i] == '\0')
		return (-1);
	else
		return (1);
}
int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = ft_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		str[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}
long ft_atoi_cust(const char *nbr)
{
	int	result;
	int	sign;
	const char *save;

	sign = 1;
	result = 0;
	save = nbr;
	if (*nbr && (*nbr == '-'))
	{
			sign *= -1;
			nbr++;
	}
	if(*nbr == '+')
		return(__LONG_MAX__);
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + result * 10;
	if(!ft_strncmp(ft_itoa(result*sign),save,ft_strlen(save)))
		return((long)result * sign);
	return(__LONG_MAX__);
}


s_list	*ft_lstnew(long nb)
{
	s_list	*new;
	new = (s_list *)malloc(sizeof(s_list));
	if (!new)
		return (NULL);
	new->nbr = nb;
	new->next = NULL;
	return (new);
}
void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
size_t ft_list_lenght(s_list *lst)
{
	size_t i;
	s_list *temp;
	temp = lst;
	i = 0;
	while(temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return(i);
}

void stack_visualizer(s_list *stack_a, s_list *stack_b)
{
	int flag = 0;
	while(stack_a && stack_b)
	{
		if(flag == 0)
			printf("Stack A\t Stack B\n");
		flag = 1;
		printf("  |%ld|\t",stack_a->nbr);
		printf("  |%ld|\t",stack_b->nbr);
		printf("\n");
		stack_a = stack_a -> next;
		stack_b = stack_b -> next;
	}
}
int		is_lst_double_nb(s_list *lst)
{
	s_list *temp;
	s_list *current;
	int check_nbr;
	int flag = 0;
	temp = lst;
	current = lst;
	while(current->next != NULL)
	{
		check_nbr = current->nbr;
		temp = current;
		current = current->next;
		while(temp->next != NULL)
		{
			if(temp->nbr == check_nbr)
				flag += 1;
			if(temp->nbr == check_nbr && flag > 1)
				return(-1);
			temp = temp->next;
		}
		flag = 0;
	}
	return(0);
}
void display_error(void)
{
	write(1,"Error\n",6);
}



