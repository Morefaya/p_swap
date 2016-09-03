#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include "ft_printf.h"

#define OPT "ab"
#define OPT_A 01
#define OPT_B 02

typedef struct	s_op
{
	char		*op;
}			t_op;

typedef struct	s_pile
{
	int		val;
}			t_pile;

int			strisnbr(const char *str);
int			puterror(int ret);
int			double_val(int *tab, int i);
int			max_int(int value, char *str);
int			check_nbr(int ac, char **av, int *tab);
void			print_op(t_list *lst);
t_list			*get_op_lst(void);
t_list			*lst_inttab(int *tab, int len);
void			do_op(t_list **lst_a, t_list **lst_b);
void			print_lst(t_list *lst_a);
void			del_content(void*, size_t);
void			del_op(void*, size_t);
void			rotate(t_list **lst);
void			swap(t_list **lst);
void			rev_rotate(t_list **lst);
void			push(t_list **lst_a, t_list **lst_b);
int			check_asc(t_list *lst);
int			get_option(int ac, char **av);
int			count_arg(int ac, char ***av);
void			operate(t_list **lst_a, t_list **lst_b, t_list **op_lst);
void			do_allop(t_list **lst_a, t_list **lst_b, t_list **op_lst);
int			count_nbr_split(char **av);
void			deal_op(int opt, t_list **lst_a, t_list **lst_b);
t_list			*deal_arg(int ac, int *opt, char **av);
char			**arg_cpy(int ac, char **av);
void			delete_cpy(char **av_cpy);
#endif
