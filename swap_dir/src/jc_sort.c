#include "push_swap.h"

int	jc_sort(t_list **lst)
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
	return (0);
}
