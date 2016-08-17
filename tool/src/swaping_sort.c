#include "push_swap.h"

void	swaping_sort(t_list **lst_a)
{
	if (check_next(*lst_a))
	{
		swap(lst_a);
		ft_putendl("sa");
	}
}
