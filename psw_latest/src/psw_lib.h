#ifndef PSW_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Printf/ft_printf.h"

typedef struct s_list
{
	long nbr;
	struct s_list *next;
} t_list;

typedef struct s_data
{
	int i;
	int flag;
	int argc;
	int counter;
	char **argv;
	
	t_list *stack_a;
	t_list *stack_b;
} t_data;

/*******************************************************************/
/*                        LIBFT CUSTOM FUNC                        */
/*******************************************************************/
long ft_atoi_cust(const char *nbr);
int	ft_strncmp(const char *first, const char *second, size_t length);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
/*******************************************************************/
/*                        LIST CUSTOM FUNC                     	   */
/*******************************************************************/

t_list	*ft_lstnew(long nb);
void	ft_lstadd_front(t_list **lst, t_list *new);
int ft_list_lenght(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*******************************************************************/
/*                        PRINT  FUNC                 			   */
/*******************************************************************/

void stack_a_visualizer(t_list *stack_a);
void stack_b_visualizer(t_list *stack_b);
void display_error(void);
void counter_print(t_data *data);

/*******************************************************************/
/*                        HANDLE ERROR FUNC               		   */
/*******************************************************************/
int		is_lst_double_nb(t_list *lst);
int is_not_null(char *str);

/*******************************************************************/
/*                        PARSER             		               */
/*******************************************************************/
int ft_psw_parser(t_data *data);

/*******************************************************************/
/*                        PUSH FUNC // SORT FUNC            	   */
/*******************************************************************/
void ft_pb(t_data *data);
void ft_pa(t_data *data);
void ft_sort(t_data *data);
int ft_is_sorted(t_data *data);
void ft_sort_3(t_data *data);
void	ft_sort_2(t_data *data);
int ft_is_sorted(t_data *data);
void ft_ra(t_data *data);
void ft_rb(t_data *data);
void ft_rra(t_data *data);
void ft_rrb(t_data *data);
void ft_sa(t_data *data);
void ft_sb(t_data *data);
void ft_ss(t_data *data);
void ft_rr(t_data *data);
void ft_rrr(t_data *data);
#endif
