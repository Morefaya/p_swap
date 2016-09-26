#include "push_swap.h"

int	check_lstlen(t_list *lst, int div)
{
	if (!lst)
		return (1);
	while (lst)
	{
		if (((t_pile*)(lst->content))->val > div)
			return (1);
		lst = lst->next;
	}
	return (0);
}
