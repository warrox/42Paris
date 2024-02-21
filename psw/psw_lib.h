#ifndef PSW_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_list
{
	long nbr;
	struct t_list *next;
} s_list;

typedef struct s_data
{
	int i;
	int flag;
	int argc;
	char **argv;
	s_list *stack_a;
	s_list *stack_b;
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

s_list	*ft_lstnew(long nb);
void	ft_lstadd_front(s_list **lst, s_list *new);
int ft_list_lenght(s_list *lst);
void	ft_lstadd_back(s_list **lst, s_list *new);

/*******************************************************************/
/*                        PRINT  FUNC                 			   */
/*******************************************************************/

void stack_visualizer(s_list *stack_a, s_list *stack_b);
void display_error(void);

/*******************************************************************/
/*                        HANDLE ERROR FUNC               		   */
/*******************************************************************/
int		is_lst_double_nb(s_list *lst);
int is_not_null(char *str);

/*******************************************************************/
/*                        PARSER             		               */
/*******************************************************************/
int ft_psw_parser(t_data *data);


#endif
