#include "push_swap.h"

void	sort_it(t_list **lst)
{
	int	max;
	int	i;
	int	var;
	int	next;

	max = get_highest(*lst);
	i = 0;
	while (check_asc_rot(*lst) != 1)
	{
		i = 0;
		while (i < ft_lstcount(*lst))
		{
			var = ((t_pile*)((*lst)->content))->val;
			next = ((t_pile*)((*lst)->next->content))->val;
			if ((check_next(*lst) && var != max))
				swap(lst);
			rotate(lst);
			i++;
		}
		i = ft_lstcount(*lst) - 1;
		while (i >= 0)
		{
			var = ((t_pile*)((*lst)->content))->val;
			next = ((t_pile*)((*lst)->next->content))->val;
			if ((check_next(*lst) && var != max))
				swap(lst);
			rev_rotate(lst);
			i--;
		}
	}
	while (check_asc(*lst) != 1)
		rotate(lst);
}
