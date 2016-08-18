#ifndef TOOL_H
# define TOOL_H

# include "libft.h"

typedef struct	s_pile
{
	int	val;
}		t_pile;

typedef struct	s_op
{
	char	*op;
}		t_op;

t_list		*check_nbr(int ac, char **av);
int		strisnbr(const char *str);
void		print_op(t_list *op_lst);
void		print_lst(t_list *lst);
void		del_content(void *content, size_t size);
void		del_op(void *content, size_t size);
int		double_val(t_list *lst, int val);
int		max_int(int val, char *str);
t_list		*get_op_lst(void);
void		do_op(t_list **lst_a, t_list **lst_b);
void		rotate(t_list **lst);
void		rev_rotate(t_list **lst);
void		swap(t_list **lst);
void		push(t_list **lst_a, t_list **lst_b);

#endif
