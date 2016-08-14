#include "push_swap.h"

void	hard_sort(t_list **lst_a, t_list **lst_b)
{
	int	low;
	int	rot;
	int	value;
	int	value_next;

	if (!lst_a)
		return ;
	else if (!*lst_a)
		return ;
	if (ft_lstcount(*lst_a) == 2)
	{
		if (check_next(*lst_a))
			swap(lst_a);
		return ;
	}
	low = get_lowest(*lst_a);
	rot = where_is(*lst_a, low);
	value = ((t_pile*)((*lst_a)->content))->val;
	value_next = ((t_pile*)((*lst_a)->next->content))->val;
	if (!rot)
	{
		push(lst_a, lst_b);
		ft_putendl("pb");	
		return ;
	}
	if (rot > 0)
	{
		rotate(lst_a);
		ft_putendl("ra");
	}
	else
	{
		rev_rotate(lst_a);
		ft_putendl("rra");	
	}
	if (value > value_next)
	{
		swap(lst_a);
		ft_putendl("sa");
	}
}
