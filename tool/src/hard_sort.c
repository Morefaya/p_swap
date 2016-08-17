#include "push_swap.h"

void	hard_sort(t_list **lst_a, t_list **lst_b)
{
	int	rot;

	if (!lst_a)
		return ;
	else if (!*lst_a)
		return ;
	if (!(rot = where_is(*lst_a, get_lowest(*lst_a))))
	{
		push(lst_a, lst_b);
		ft_putendl("pb");
	}
	else if (rot > 0)
	{
		rotate(lst_a);
		ft_putendl("ra");
	}
	else
	{
		rev_rotate(lst_a);
		ft_putendl("rra");
		swaping_sort(lst_a);
	}
	//swaping_sort(lst_a);
}
