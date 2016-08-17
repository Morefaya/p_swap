
#include "push_swap.h"

int	danm_sort(t_list **lst_a, t_list **lst_b, int opt)
{
	int	nb_link;
	int	median;
	int	i;
	int	ret;

	nb_link = ft_lstcount(*lst_a);
	if (nb_link == 2)
	{
		if ((check_next(*lst_a) && opt) || (!check_next(*lst_a) && !opt))
				swaping_sort(lst_a);
		return (1);
	}
	median = lst_median(*lst_a);
	i = 0;
	ret = 0;
	while (i < nb_link)
	{
		if ((((t_pile*)((*lst_a)->content))->val < median && opt)
			|| (((t_pile*)((*lst_a)->content))->val >= median && !opt))
		{
			ret++;
			push(lst_a, lst_b);
			ft_putendl("pa");
		}
		else
		{
			rotate(lst_a);
			ft_putendl("ra");
		}
		i++;
	}
	return (ret);
}
