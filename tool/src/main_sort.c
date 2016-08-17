
#include "push_swap.h"

void	main_sort(t_list **lst_a, t_list **lst_b)
{
	while (42)
	{
		if (ft_lstcount(*lst_a) == 2)
		{
			swaping_sort(lst_a);
			break ;
		}
		else if (ft_lstcount(*lst_a) == 3)
		{
			if (check_asc_rot(*lst_a) == 1)
				turn_list(lst_a);
			else
			{
				swap(lst_a);
				ft_putendl("sa");
				if (check_asc_rot(*lst_a) == 1)
					turn_list(lst_a);
			}
			break ;
		}
		hard_sort(lst_a, lst_b);
	}
}
