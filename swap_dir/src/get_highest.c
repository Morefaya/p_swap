#include "push_swap.h"

int		get_highest(t_list *lst)
{
	int		high;

	if (!lst)
		return (0);
	high = ((t_pile*)(lst->content))->val;
	while (lst)
	{
		if (((t_pile*)(lst->content))->val > high)
			high = ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (high);
}
