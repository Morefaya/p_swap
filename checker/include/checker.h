#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"

typedef struct	s_op
{
	char	*op;
}		t_op;

int	strisnbr(const char *str);
int	puterror(int *tab, int ret);
int	double_val(int *tab, int i);
int	max_int(int value, char *str);
int	check_nbr(int ac, char **av, int *tab);
void	print_op(t_list *lst);

#endif
