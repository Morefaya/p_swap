#include "push_swap.h"

static void	help_low(t_list **lst, int high, int asc)
{
	if (get_next(*lst) == high)
	{
		ft_putchar('a');
		if (asc)
		{
			ft_putchar('b');
			swap(lst);
			rotate(lst);
		}
	}
	else if (get_prev(*lst) == high)
	{
		ft_putchar('c');
	}
}

static void	help_high(t_list **lst, int low, int asc)
{
	if (get_next(*lst) == low)
	{
		ft_putchar('d');
		if (!asc)
		{
			swap(lst);
			rotate(lst);
		}
		else if (asc)
			rotate(lst);
	}
	else if (get_prev(*lst) == low)
	{
		ft_putchar('e');
		if (asc)
		{
			ft_putchar('f');
			rev_rotate(lst);
			swap(lst);
			rotate(lst); //facultative
		}
	}
}

int		jc_sort(t_list **lst)
{
	int	high;
	int	low;
	int	r_high;
	int	r_low;
	int	i;
	int	rot;

	high = get_highest(*lst);
	low = get_lowest(*lst);
	r_high = where_is(*lst, high);
	r_low = where_is(*lst, low);
	rot = (ft_abs(r_low) <= ft_abs(r_high)) ? r_low : r_high;
	i = 0;
	if (rot > 0)
		while (i++ < rot)
			rotate(lst);
	else if (rot < 0)
		while (i++ < ft_abs(rot))
			rev_rotate(lst);
	if (rot == r_low)
	{
		lst_trans(lst, where_is(*lst, high));
		help_low(lst, high, 1);
	}
	else if (rot == r_high)
	{
		lst_trans(lst, where_is(*lst, low));
		help_high(lst, low, 1);
	}
	return (0);
}
