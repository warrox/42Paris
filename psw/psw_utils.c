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

static int	count_words(char const *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(char const *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_tab(char **split)
{
	size_t	j;

	j = 0;
	while (split[j] != NULL)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

char	**split_fill(char const *s, char c, char **split)
{
	size_t	j;
	int		index;
	int		i;

	index = -1;
	i = -1;
	j = 0;
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (!split[j - 1])
				return (free_tab(split));
			index = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = split_fill(s, c, split);
	return (split);
}

int is_not_null(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	if(i == 0)
	{
		printf("NULL detected");
		return(1);
	}
	return(0);
}



