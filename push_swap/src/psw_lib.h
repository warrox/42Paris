/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:05 by whamdi            #+#    #+#             */
/*   Updated: 2024/03/22 14:11:23 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_LIB_H
# include "../Printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define UP 1
# define DOWN 2

typedef struct s_list
{
	long			nbr;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	int				i;
	int				flag;
	int				argc;
	int				counter;
	char			**argv;
	int				cost_a[2];
	int				cost_b[2];
	int				index_b;
	int				final_cost;
	int				f_cost_a[2];
	int				f_cost_b[2];
	int				nbr;
	int				index;
	int				f_index;
	int				dif;
	int				best_dif;
	int				cur_lowest;

	t_list			*stack_a;
	t_list			*stack_b;
}					t_data;

/*******************************************************************/
/*                        LIBFT CUSTOM FUNC                        */
/*******************************************************************/
long				ft_atoi_cust(const char *nbr);
int					ft_strncmp(const char *first, const char *second,
						size_t length);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
void				split_destroy(char **split);
/*******************************************************************/
/*                        LIST CUSTOM FUNC                     		*/
/*******************************************************************/

t_list				*ft_lstnew(long nb);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_list_lenght(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);

/*******************************************************************/
/*                        PRINT  FUNC                 				*/
/*******************************************************************/

void				display_error(t_data *data);

/*******************************************************************/
/*                        HANDLE ERROR FUNC               			*/
/*******************************************************************/
int					is_lst_double_nb(t_list *lst);
int					is_not_null(char *str);

/*******************************************************************/
/*                        PARSER             							*/
/*******************************************************************/
int					ft_psw_parser(t_data *data);

/*******************************************************************/
/*                        PUSH FUNC // SORT FUNC            		*/
/*******************************************************************/

void				ft_pb(t_data *data);
void				ft_pa(t_data *data);
void				ft_sort(t_data *data);
int					ft_is_sorted(t_data *data);
void				ft_sort_3(t_data *data);
void				ft_sort_2(t_data *data);
int					ft_is_sorted(t_data *data);
void				ft_cost_mediane(t_list *stack, int i, int *cost);
void				ft_ra(t_data *data, int flag);
void				ft_rb(t_data *data, int flag);
void				ft_rra(t_data *data, int flag);
void				ft_rrb(t_data *data, int flag);
void				ft_sa(t_data *data, int flag);
void				ft_sb(t_data *data, int flag);
void				ft_ss(t_data *data);
void				ft_rr(t_data *data);
void				ft_rrr(t_data *data);
int					ft_lowest_cost_sa(t_data *data, t_list *stack);
int					ft_is_sorted(t_data *data);
int					lower_nbr(t_list *stack_b);
int					index_lower_nbr(t_list *stack_b);
int					index_higher_nbr(t_list *stack_b);
int					is_max_or_min(t_list *stack_a, t_list *stack_b);
int					index_middle_nbr(t_data *data);
int					index_middle_nbr_a(t_data *data);
int					higher_nbr(t_list *stack_b);
int					ft_simplify_cost(t_data *data);
void				ft_action_a(t_data *data);
void				ft_data_cost_init(t_data *data);
void				ft_act_up(t_data *data);
void				ft_act_down(t_data *data);
int					index_higher_nbr(t_list *stack_b);
int					find_nbr(t_list *stack, int index);
int					is_max_or_min_a(t_list *stack_a, t_list *stack_b);
void				ft_data_cost_init(t_data *data);
int					push_lowest_top(t_list *a);
void				ft_lowest_top_in_a(t_data *data);
#endif
