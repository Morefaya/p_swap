#include "push_swap.h"

void	lst_trans(t_list **lst, int range)
{
	int	i;

	if (!range)
		return ;
	i = ft_abs(range);
	while (i--)
	{
		if (range < 0)
			rev_rotate(lst);
		swap(lst);
		if (range > 0)
			rotate(lst);
	}
}
