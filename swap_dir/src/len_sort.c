#include "push_swap.h"

static void	step(t_list **lst, t_mark *mark, int *cond, int *i)
{
	if ((check_next(*lst) && mark->asc)
		|| (!check_next(*lst) && !mark->asc))
	{
		*cond = 1;
		s_local(lst, mark);
	}
	else
		*cond = 0;
	if (*cond && *i)
	{
		rev_local(lst, mark);
		(*i)--;
	}
	else if (!*cond || (*cond && !*i))
	{
		r_local(lst, mark);
		(*i)++;
	}
}

void	len_sort(t_list **lst, t_mark *mark, int len)
{
	int	i;
	int	cond;

	i = 0;
	cond = 1;
	while (i < len - 1)
	{
		step(lst, mark, &cond, &i);
		//ft_printf("nbr i: %d\n", i);
		//print_lst(*lst);
	}
	r_local(lst, mark);
}
