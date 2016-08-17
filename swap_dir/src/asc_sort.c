#include "push_swap.h"

int	asc_sort(t_list **lst)
{
	if (!lst)
		return (0);
	else if (!*lst)
		return (0);
	else if (!(*lst)->next)
		return (0);
	if (check_asc_rot(*lst) != 1)
	{
		if (!check_prev(*lst) && !check_next(*lst))
		{
			if (check_prevnext(*lst))
				return (REV);
			else
				return (R);
		}
		else if (check_prev(*lst) && !check_next(*lst))
			return (R);
		else if (!check_prev(*lst) && check_next(*lst))
			return (S);	
		else if (check_prev(*lst) && check_next(*lst))
			return (S);
	}
	return (0);
}
