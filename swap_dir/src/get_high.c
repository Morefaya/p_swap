#include "push_swap.h"

int		get_high(t_list *lst, int len)
{
	int		high;

	if (!lst)
		return (0);
	high = ((t_pile*)(lst->content))->val;
	while (lst && len--)
	{
		if (((t_pile*)(lst->content))->val > high)
			high = ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (high);
}
