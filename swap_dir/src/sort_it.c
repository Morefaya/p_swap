#include "push_swap.h"

void	sort_it(t_list **lst)
{
	int	len;
	int	max;
	int	i;
	int	min;
	int	var;
	int	next;

	len = ft_lstcount(*lst);
	max = get_highest(*lst);
	min = get_lowest(*lst);
	i = 0;
	while (check_asc_rot(*lst) != 1)
	{
		i = 0;
		while (i < len)
		{
			var = ((t_pile*)((*lst)->content))->val;
			next = ((t_pile*)((*lst)->next->content))->val;
			if ((check_next(*lst) && var != max))
				swap(lst);
			rotate(lst);
			i++;
		}
		i = len - 1;
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
