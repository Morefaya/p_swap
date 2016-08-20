#include "push_swap.h"

static void	help_low(t_list **lst, int high, int asc)
{
	if (get_next(*lst) == high)
	{
		//ft_putchar('a');
		if (asc)
		{
			//ft_putchar('b');
			swap(lst);
			rotate(lst);
		}
		else
		{
			//ft_putchar('B');
			rotate(lst);
		}
	}
	else if (get_prev(*lst) == high)
	{
		//ft_putchar('c');
		if (!asc)
		{
			rev_rotate(lst);
			swap(lst);
			rotate(lst);
		}
	}
}

static void	help_high(t_list **lst, int low, int asc)
{
	if (get_next(*lst) == low)
	{
		//ft_putchar('d');
		if (!asc)
		{
		//	ft_putchar('D');
			swap(lst);
			rotate(lst);
		}
		else if (asc)
		{
		//	ft_putchar('e');
			rotate(lst);
		}
	}
	else if (get_prev(*lst) == low)
	{
		//ft_putchar('f');
		if (asc)
		{
		//	ft_putchar('g');
			rev_rotate(lst);
			swap(lst);
			rotate(lst); //facultative
		}
		else
		{
		//	ft_putchar('h');
		}
	}
}

int		jc_sort(t_list **lst, int asc)
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
		help_low(lst, high, asc);
	}
	else if (rot == r_high)
	{
		lst_trans(lst, where_is(*lst, low));
		help_high(lst, low, asc);
	}
	return (0);
}
