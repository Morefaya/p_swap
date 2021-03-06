#include "push_swap.h"

void	elem_sort(t_list **lst, t_mark *mark, int range)
{
	int	len;

	if (!lst || range > 3 || range < 2)
		return ;
	else if ((len = ft_lstcount(*lst)) < 2)
		return ;
	if (range == 2 && check_next(*lst))
		s_local(lst, mark);
	else if (range == 3)
	{
		if (check_next(*lst))
			s_local(lst, mark);
		if (check_next((*lst)->next))
		{
			r_local(lst, mark);
			s_local(lst, mark);
			rev_local(lst, mark);
			if (check_next(*lst))
				s_local(lst, mark);
		}
	}
}
