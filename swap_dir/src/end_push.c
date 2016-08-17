#include "push_swap.h"

void	end_push(t_list **lst_a, t_list **lst_b)
{
	while (*lst_b)
	{
		push(lst_b, lst_a);
		ft_putendl("pa");
	}
}
